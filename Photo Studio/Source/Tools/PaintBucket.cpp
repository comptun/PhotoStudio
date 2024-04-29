#include "PaintBucket.h"

static void push(std::vector<int>& stack, int x, int y)
{
	// C++'s std::vector can act as a stack and manage memory for us
	stack.push_back(x);
	stack.push_back(y);
}

static bool pop(std::vector<int>& stack, int& x, int& y)
{
	if (stack.size() < 2) return false; // it's empty
	y = stack.back();
	stack.pop_back();
	x = stack.back();
	stack.pop_back();
	return true;
}

static uint32_t GetColor() {
	glm::vec4 c = WindowData::m_Color;
	uint32_t
		r = (uint32_t)std::clamp(c[0] * 255.0f, 0.0f, 255.0f),
		g = (uint32_t)std::clamp(c[1] * 255.0f, 0.0f, 255.0f) << 8,
		b = (uint32_t)std::clamp(c[2] * 255.0f, 0.0f, 255.0f) << 16,
		a = (uint32_t)std::clamp(c[3] * 255.0f, 0.0f, 255.0f) << 24;

	return r | g | b | a;
}

void PaintBucket::FloodFill4Stack(std::shared_ptr<Layer> Layer, PixelBuffer& PBuffer, glm::vec3 Pos)
{
	static glm::vec3 PreviousPosition = { -1,-1,-1 };

	if (!(Input::Mouse::Button == SDL_BUTTON_LEFT && Input::Mouse::State == SDL_PRESSED && Input::Mouse::m_InitialClick && Input::Mouse::m_MouseInCanvas)) {
		return;
	}

	if (!(Pos.x >= 0 && Pos.y >= 0 && Pos.x < CanvasData::m_CanvasSize.x && Pos.y < CanvasData::m_CanvasSize.y)) {
		return;
	}

	if (Pos == PreviousPosition) {
		return;
	}

	PBuffer.Download();

	auto Pixels32 = std::unique_ptr<uint32_t[]>(new uint32_t[PBuffer.m_NumBytes / 4]);
	//uint32_t* Pixels32 = reinterpret_cast<uint32_t*>(copyMem.get());
	memcpy(Pixels32.get(), PBuffer.m_Pixels, PBuffer.m_NumBytes);

	uint32_t newColor =	GetColor();
	
	int x = Pos.x, y = Pos.y;
	int w = PBuffer.m_Width, h = PBuffer.m_Height;

	uint32_t oldColor = Pixels32[y * w + x];

	if (newColor == oldColor) {
		return;
	}

	//std::cout << std::hex << newColor << " " << oldColor << "\n";

	static const int dx[4] = { 0, 1, 0, -1 }; // relative neighbor x coordinates
	static const int dy[4] = { -1, 0, 1, 0 }; // relative neighbor y coordinates

	std::vector<int> stack;
	push(stack, x, y);
	while (pop(stack, x, y))
	{
		Pixels32[y * w + x] = newColor;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < w && ny >= 0 && ny < h && Pixels32[ny * w + nx] == oldColor) {
				push(stack, nx, ny);
			}
		}
	}

	Layer->Rescale(reinterpret_cast<unsigned char*>(Pixels32.get()), PBuffer.m_Width, PBuffer.m_Height);
	PreviousPosition = Pos;
}