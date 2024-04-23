#include "PixelBuffer.h"

PixelBuffer::PixelBuffer(GLenum Format, int Width, int Height, int Number)
	: m_Format(Format),
	m_PBOs(nullptr),
	m_NumPBOs(Number),
	m_Index(0),
	m_NumDownloads(0),
	m_Width(Width),
	m_Height(Height),
	m_NumBytes(0),
	m_Pixels(nullptr)
{
	Init();
}
PixelBuffer::~PixelBuffer()
{
	if (m_Pixels != nullptr) {
		delete[] m_Pixels;
		m_Pixels = nullptr;
	}
}
void PixelBuffer::Download()
{
    unsigned char* ptr;

    if (m_NumDownloads < m_NumPBOs) {
        /*
           First we need to make sure all our pbos are bound, so glMap/Unmap will
           read from the oldest bound buffer first.
        */
        glBindBuffer(GL_PIXEL_PACK_BUFFER, m_PBOs[m_Index]);
        glReadPixels(0, 0, m_Width, m_Height, m_Format, GL_UNSIGNED_BYTE, 0);   /* When a GL_PIXEL_PACK_BUFFER is bound, the last 0 is used as offset into the buffer to read into. */
    }
    else {
        /* Read from the oldest bound pbo. */
        glBindBuffer(GL_PIXEL_PACK_BUFFER, m_PBOs[m_Index]);

        ptr = (unsigned char*)glMapBuffer(GL_PIXEL_PACK_BUFFER, GL_READ_ONLY);
        if (NULL != ptr) {
            memcpy(m_Pixels, ptr, m_NumBytes);
            glUnmapBuffer(GL_PIXEL_PACK_BUFFER);
        }

        /* Trigger the next read. */
        glReadPixels(0, 0, m_Width, m_Height, m_Format, GL_UNSIGNED_BYTE, 0);
    }

    m_Index += 1;
    m_Index = m_Index % m_NumPBOs;

    m_NumDownloads++;
    if (m_NumDownloads == UINT64_MAX) {
        m_NumDownloads = m_NumPBOs;
    }

    glBindBuffer(GL_PIXEL_PACK_BUFFER, 0);
}

void PixelBuffer::Init()
{
    if (GL_RED == m_Format || GL_GREEN == m_Format || GL_BLUE == m_Format) {
        m_NumBytes = m_Width * m_Height;
    }
    else if (GL_RGB == m_Format || GL_BGR == m_Format) {
        m_NumBytes = m_Width * m_Height * 3;
    }
    else if (GL_RGBA == m_Format || GL_BGRA == m_Format) {
        m_NumBytes = m_Width * m_Height * 4;
    }

    m_PBOs = new GLuint[m_NumPBOs];

    m_Pixels = new unsigned char[m_NumBytes];

    glGenBuffers(m_NumPBOs, m_PBOs);
    for (int i = 0; i < m_NumPBOs; ++i) {
        glBindBuffer(GL_PIXEL_PACK_BUFFER, m_PBOs[i]);
        glBufferData(GL_PIXEL_PACK_BUFFER, m_NumBytes, NULL, GL_STREAM_READ);
    }

    glBindBuffer(GL_PIXEL_PACK_BUFFER, 0);
}