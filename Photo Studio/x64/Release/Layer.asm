; Listing generated by Microsoft (R) Optimizing Compiler Version 19.36.32535.0 

include listing.inc

INCLUDELIB OLDNAMES

PUBLIC	??$forward@V?$allocator@D@std@@@std@@YA$$QEAV?$allocator@D@0@AEAV10@@Z ; std::forward<std::allocator<char> >
PUBLIC	??$_Construct@$01PEBD@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAAXQEBD_K@Z ; std::basic_string<char,std::char_traits<char>,std::allocator<char> >::_Construct<2,char const *>
PUBLIC	??$?0V?$allocator@D@std@@$$V@?$_Compressed_pair@V?$allocator@D@std@@V?$_String_val@U?$_Simple_types@D@std@@@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@$$QEAV?$allocator@D@1@@Z ; std::_Compressed_pair<std::allocator<char>,std::_String_val<std::_Simple_types<char> >,1>::_Compressed_pair<std::allocator<char>,std::_String_val<std::_Simple_types<char> >,1><std::allocator<char> >
PUBLIC	?select_on_container_copy_construction@?$_Default_allocator_traits@V?$allocator@D@std@@@std@@SA?AV?$allocator@D@2@AEBV32@@Z ; std::_Default_allocator_traits<std::allocator<char> >::select_on_container_copy_construction
PUBLIC	?_Myptr@?$_String_val@U?$_Simple_types@D@std@@@std@@QEBAPEBDXZ ; std::_String_val<std::_Simple_types<char> >::_Myptr
PUBLIC	??0?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAA@AEBV01@@Z ; std::basic_string<char,std::char_traits<char>,std::allocator<char> >::basic_string<char,std::char_traits<char>,std::allocator<char> >
PUBLIC	??1Layer@@QEAA@XZ				; Layer::~Layer
PUBLIC	?GetName@Layer@@QEAA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ ; Layer::GetName
PUBLIC	??0Layer@@QEAA@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_K11U?$vec@$03M$0A@@glm@@@Z ; Layer::Layer
;	COMDAT pdata
pdata	SEGMENT
$pdata$??$_Construct@$01PEBD@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAAXQEBD_K@Z DD imagerel $LN78@Construct
	DD	imagerel $LN78@Construct+243
	DD	imagerel $unwind$??$_Construct@$01PEBD@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAAXQEBD_K@Z
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$??0?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAA@AEBV01@@Z DD imagerel $LN95@basic_stri
	DD	imagerel $LN95@basic_stri+277
	DD	imagerel $unwind$??0?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAA@AEBV01@@Z
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$??1Layer@@QEAA@XZ DD imagerel $LN42
	DD	imagerel $LN42+144
	DD	imagerel $unwind$??1Layer@@QEAA@XZ
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$?GetName@Layer@@QEAA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ DD imagerel $LN7@GetName
	DD	imagerel $LN7@GetName+30
	DD	imagerel $unwind$?GetName@Layer@@QEAA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$??0Layer@@QEAA@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_K11U?$vec@$03M$0A@@glm@@@Z DD imagerel $LN47
	DD	imagerel $LN47+315
	DD	imagerel $unwind$??0Layer@@QEAA@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_K11U?$vec@$03M$0A@@glm@@@Z
;	COMDAT xdata
xdata	SEGMENT
$ip2state$??0Layer@@QEAA@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_K11U?$vec@$03M$0A@@glm@@@Z DB 08H
	DB	090H
	DB	02H
	DB	'8'
	DB	04H
	DB	01cH
	DB	06H
	DB	0b0H
	DB	00H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$stateUnwindMap$??0Layer@@QEAA@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_K11U?$vec@$03M$0A@@glm@@@Z DB 06H
	DB	0cH
	DD	imagerel ??1?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAA@XZ
	DB	050H
	DB	034H
	DD	imagerel ??1Framebuffer@@QEAA@XZ
	DB	040H
	DB	036H
	DD	imagerel ?dtor$2@?0???0Layer@@QEAA@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_K11U?$vec@$03M$0A@@glm@@@Z@4HA
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$cppxdata$??0Layer@@QEAA@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_K11U?$vec@$03M$0A@@glm@@@Z DB 028H
	DD	imagerel $stateUnwindMap$??0Layer@@QEAA@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_K11U?$vec@$03M$0A@@glm@@@Z
	DD	imagerel $ip2state$??0Layer@@QEAA@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_K11U?$vec@$03M$0A@@glm@@@Z
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$??0Layer@@QEAA@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_K11U?$vec@$03M$0A@@glm@@@Z DD 081f19H
	DD	0103410H
	DD	0f00c7210H
	DD	07008e00aH
	DD	050066007H
	DD	imagerel __GSHandlerCheck_EH4
	DD	imagerel $cppxdata$??0Layer@@QEAA@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_K11U?$vec@$03M$0A@@glm@@@Z
	DD	032H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?GetName@Layer@@QEAA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ DQ 03002520600020601r ; 1.97773e-77
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$ip2state$??1Layer@@QEAA@XZ DB 06H
	DB	0baH
	DB	02H
	DB	','
	DB	04H
	DB	' '
	DB	00H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$stateUnwindMap$??1Layer@@QEAA@XZ DB 04H
	DB	0eH
	DD	imagerel __imp___std_terminate
	DB	02eH
	DD	imagerel __imp___std_terminate
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$cppxdata$??1Layer@@QEAA@XZ DB 068H
	DD	imagerel $stateUnwindMap$??1Layer@@QEAA@XZ
	DD	imagerel $ip2state$??1Layer@@QEAA@XZ
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$??1Layer@@QEAA@XZ DD 020619H
	DD	030023206H
	DD	imagerel __CxxFrameHandler4
	DD	imagerel $cppxdata$??1Layer@@QEAA@XZ
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$??0?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAA@AEBV01@@Z DQ 0000a340d00060d01r ; 1.41895e-308
	DQ	060067007e009320dr		; 3.76049e+154
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$??$_Construct@$01PEBD@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAAXQEBD_K@Z DQ 0000b340c00060c01r ; 1.55801e-308
	DQ	0500660077008320cr		; 3.23858e+77
; Function compile flags: /Ogtpy
; File C:\dev\Photo Studio\Photo Studio\Source\Layer.cpp
; File C:\dev\Photo Studio\Photo Studio\Dependencies\glm\detail\type_vec2.inl
; File C:\dev\Photo Studio\Photo Studio\Source\Layer.cpp
; File C:\dev\Photo Studio\Photo Studio\Source\Framebuffer.cpp
; File C:\dev\Photo Studio\Photo Studio\Source\Layer.cpp
; File C:\dev\Photo Studio\Photo Studio\Source\Framebuffer.cpp
; File C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.36.32532\include\xstring
; File C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.36.32532\include\xmemory
; File C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.36.32532\include\xstring
; File C:\dev\Photo Studio\Photo Studio\Source\Layer.cpp
; File C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.36.32532\include\xmemory
; File C:\dev\Photo Studio\Photo Studio\Source\Layer.cpp
;	COMDAT ??0Layer@@QEAA@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_K11U?$vec@$03M$0A@@glm@@@Z
_TEXT	SEGMENT
this$GSCopy$ = 32
LayerName$GSCopy$ = 40
__$ArrayPad$ = 48
this$ = 112
LayerName$ = 120
Index$dead$ = 128
Width$ = 136
Height$ = 144
Color$ = 152
??0Layer@@QEAA@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_K11U?$vec@$03M$0A@@glm@@@Z PROC ; Layer::Layer, COMDAT

; 9    : {

$LN47:
	mov	QWORD PTR [rsp+24], rbx
	push	rbp
	push	rsi
	push	rdi
	push	r14
	push	r15
	sub	rsp, 64					; 00000040H
	mov	rax, QWORD PTR __security_cookie
	xor	rax, rsp
	mov	QWORD PTR __$ArrayPad$[rsp], rax
	mov	rsi, r9
	mov	r14, rdx
	mov	rbp, rcx
	mov	QWORD PTR this$GSCopy$[rsp], rcx
	mov	QWORD PTR LayerName$GSCopy$[rsp], rdx
	mov	rbx, QWORD PTR Height$[rsp]
	mov	rdi, QWORD PTR Color$[rsp]

; 4    :     : Framebuffer(nullptr, Width, Height),

	mov	r9, rbx
	mov	r8, rsi
	call	??0Framebuffer@@QEAA@PEAE_K1@Z		; Framebuffer::Framebuffer
	npad	1

; 6    :     m_Visible(true),

	mov	BYTE PTR [rbp+32], 1
; File C:\dev\Photo Studio\Photo Studio\Dependencies\glm\detail\type_vec2.inl

; 53   : 		: x(static_cast<T>(_x))

	xor	r15d, r15d
	mov	QWORD PTR [rbp+36], r15
	mov	QWORD PTR [rbp+44], r15
; File C:\dev\Photo Studio\Photo Studio\Source\Layer.cpp

; 5    :     m_LayerName(LayerName),

	lea	rcx, QWORD PTR [rbp+56]
	mov	rdx, r14
	call	??0?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAA@AEBV01@@Z ; std::basic_string<char,std::char_traits<char>,std::allocator<char> >::basic_string<char,std::char_traits<char>,std::allocator<char> >
	npad	1
; File C:\dev\Photo Studio\Photo Studio\Source\Framebuffer.cpp

; 49   : 	glBindFramebuffer(GL_FRAMEBUFFER, m_FBO);

	mov	edx, DWORD PTR [rbp+16]
	mov	ecx, 36160				; 00008d40H
	call	QWORD PTR glad_glBindFramebuffer
; File C:\dev\Photo Studio\Photo Studio\Source\Layer.cpp

; 12   :     Rescale(nullptr, Width, Height);

	mov	r9, rbx
	mov	r8, rsi
	xor	edx, edx
	mov	rcx, rbp
	call	?Rescale@Framebuffer@@QEAAXPEAE_K1@Z	; Framebuffer::Rescale

; 13   :     glViewport(0, 0, Width, Height);

	mov	r9d, ebx
	mov	r8d, esi
	xor	edx, edx
	xor	ecx, ecx
	call	QWORD PTR glad_glViewport

; 14   :     glClearColor(Color.r, Color.g, Color.b, Color.a);

	movss	xmm3, DWORD PTR [rdi+12]
	movss	xmm2, DWORD PTR [rdi+8]
	movss	xmm1, DWORD PTR [rdi+4]
	movss	xmm0, DWORD PTR [rdi]
	call	QWORD PTR glad_glClearColor

; 15   :     glClear(GL_COLOR_BUFFER_BIT);

	mov	ecx, 16384				; 00004000H
	call	QWORD PTR glad_glClear
; File C:\dev\Photo Studio\Photo Studio\Source\Framebuffer.cpp

; 53   : 	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	xor	edx, edx
	mov	ecx, 36160				; 00008d40H
	call	QWORD PTR glad_glBindFramebuffer
	npad	1
; File C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.36.32532\include\xstring

; 2282 :         return _BUF_SIZE <= _Myres;

	mov	rdx, QWORD PTR [r14+24]
	cmp	rdx, 16

; 4868 :         if (_My_data._Large_string_engaged()) {

	jb	SHORT $LN26@Layer

; 4869 :             _ASAN_STRING_REMOVE(*this);
; 4870 :             const pointer _Ptr = _My_data._Bx._Ptr;
; 4871 :             auto& _Al          = _Getal();
; 4872 :             _Destroy_in_place(_My_data._Bx._Ptr);
; 4873 :             _My_data._Activate_SSO_buffer();
; 4874 :             _Al.deallocate(_Ptr, _My_data._Myres + 1);

	inc	rdx
; File C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.36.32532\include\xmemory

; 946  :         _Deallocate<_New_alignof<_Ty>>(_Ptr, sizeof(_Ty) * _Count);

	mov	rcx, QWORD PTR [r14]

; 251  :         if (_Bytes >= _Big_allocation_threshold) { // boost the alignment of big allocations to help autovectorization

	cmp	rdx, 4096				; 00001000H
	jb	SHORT $LN38@Layer

; 147  :     _Bytes += _Non_user_size;

	add	rdx, 39					; 00000027H

; 148  : 
; 149  :     const uintptr_t* const _Ptr_user = static_cast<uintptr_t*>(_Ptr);
; 150  :     const uintptr_t _Ptr_container   = _Ptr_user[-1];

	mov	r8, QWORD PTR [rcx-8]

; 151  : 
; 152  :     // If the following asserts, it likely means that we are performing
; 153  :     // an aligned delete on memory coming from an unaligned allocation.
; 154  :     _STL_ASSERT(_Ptr_user[-2] == _Big_allocation_sentinel, "invalid argument");
; 155  : 
; 156  :     // Extra paranoia on aligned allocation/deallocation; ensure _Ptr_container is
; 157  :     // in range [_Min_back_shift, _Non_user_size]
; 158  : #ifdef _DEBUG
; 159  :     constexpr uintptr_t _Min_back_shift = 2 * sizeof(void*);
; 160  : #else // ^^^ _DEBUG / !_DEBUG vvv
; 161  :     constexpr uintptr_t _Min_back_shift = sizeof(void*);
; 162  : #endif // _DEBUG
; 163  :     const uintptr_t _Back_shift = reinterpret_cast<uintptr_t>(_Ptr) - _Ptr_container;

	sub	rcx, r8

; 164  :     _STL_VERIFY(_Back_shift >= _Min_back_shift && _Back_shift <= _Non_user_size, "invalid argument");

	lea	rax, QWORD PTR [rcx-8]
	cmp	rax, 31
	ja	SHORT $LN35@Layer

; 165  :     _Ptr = reinterpret_cast<void*>(_Ptr_container);

	mov	rcx, r8
$LN38@Layer:

; 255  :         ::operator delete(_Ptr, _Bytes);

	call	??3@YAXPEAX_K@Z				; operator delete
$LN26@Layer:
; File C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.36.32532\include\xstring

; 4877 :         _My_data._Mysize = 0;

	mov	QWORD PTR [r14+16], r15

; 4878 :         _My_data._Myres  = _BUF_SIZE - 1;

	mov	QWORD PTR [r14+24], 15

; 4879 :         // the _Traits::assign is last so the codegen doesn't think the char write can alias this
; 4880 :         _Traits::assign(_My_data._Bx._Buf[0], _Elem());

	mov	BYTE PTR [r14], 0
; File C:\dev\Photo Studio\Photo Studio\Source\Layer.cpp

; 18   : }

	mov	rax, rbp
	mov	rcx, QWORD PTR __$ArrayPad$[rsp]
	xor	rcx, rsp
	call	__security_check_cookie
	mov	rbx, QWORD PTR [rsp+128]
	add	rsp, 64					; 00000040H
	pop	r15
	pop	r14
	pop	rdi
	pop	rsi
	pop	rbp
	ret	0
$LN35@Layer:
; File C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.36.32532\include\xmemory

; 164  :     _STL_VERIFY(_Back_shift >= _Min_back_shift && _Back_shift <= _Non_user_size, "invalid argument");

	call	QWORD PTR __imp__invalid_parameter_noinfo_noreturn
	int	3
$LN44@Layer:
??0Layer@@QEAA@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_K11U?$vec@$03M$0A@@glm@@@Z ENDP ; Layer::Layer
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT text$x
text$x	SEGMENT
this$GSCopy$ = 32
LayerName$GSCopy$ = 40
__$ArrayPad$ = 48
this$ = 112
LayerName$ = 120
Index$dead$ = 128
Width$ = 136
Height$ = 144
Color$ = 152
?dtor$0@?0???0Layer@@QEAA@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_K11U?$vec@$03M$0A@@glm@@@Z@4HA PROC ; `Layer::Layer'::`1'::dtor$0
	mov	rcx, QWORD PTR LayerName$GSCopy$[rdx]
	jmp	??1?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAA@XZ ; std::basic_string<char,std::char_traits<char>,std::allocator<char> >::~basic_string<char,std::char_traits<char>,std::allocator<char> >
?dtor$0@?0???0Layer@@QEAA@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_K11U?$vec@$03M$0A@@glm@@@Z@4HA ENDP ; `Layer::Layer'::`1'::dtor$0
text$x	ENDS
; Function compile flags: /Ogtpy
;	COMDAT text$x
text$x	SEGMENT
this$GSCopy$ = 32
LayerName$GSCopy$ = 40
__$ArrayPad$ = 48
this$ = 112
LayerName$ = 120
Index$dead$ = 128
Width$ = 136
Height$ = 144
Color$ = 152
?dtor$1@?0???0Layer@@QEAA@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_K11U?$vec@$03M$0A@@glm@@@Z@4HA PROC ; `Layer::Layer'::`1'::dtor$1
	mov	rcx, QWORD PTR this$GSCopy$[rdx]
	jmp	??1Framebuffer@@QEAA@XZ			; Framebuffer::~Framebuffer
?dtor$1@?0???0Layer@@QEAA@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_K11U?$vec@$03M$0A@@glm@@@Z@4HA ENDP ; `Layer::Layer'::`1'::dtor$1
text$x	ENDS
; Function compile flags: /Ogtpy
;	COMDAT text$x
text$x	SEGMENT
this$GSCopy$ = 32
LayerName$GSCopy$ = 40
__$ArrayPad$ = 48
this$ = 112
LayerName$ = 120
Index$dead$ = 128
Width$ = 136
Height$ = 144
Color$ = 152
?dtor$2@?0???0Layer@@QEAA@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_K11U?$vec@$03M$0A@@glm@@@Z@4HA PROC ; `Layer::Layer'::`1'::dtor$2
	mov	rcx, QWORD PTR this$GSCopy$[rdx]
	add	rcx, 56					; 00000038H
	jmp	??1?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAA@XZ ; std::basic_string<char,std::char_traits<char>,std::allocator<char> >::~basic_string<char,std::char_traits<char>,std::allocator<char> >
?dtor$2@?0???0Layer@@QEAA@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_K11U?$vec@$03M$0A@@glm@@@Z@4HA ENDP ; `Layer::Layer'::`1'::dtor$2
text$x	ENDS
; Function compile flags: /Ogtpy
; File C:\dev\Photo Studio\Photo Studio\Source\Layer.cpp
; File C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.36.32532\include\xstring
; File C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.36.32532\include\xmemory
; File C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.36.32532\include\xstring
; File C:\dev\Photo Studio\Photo Studio\Source\Framebuffer.cpp
; File C:\dev\Photo Studio\Photo Studio\Source\Texture.cpp
; File C:\dev\Photo Studio\Photo Studio\Source\Layer.cpp
; File C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.36.32532\include\xmemory
; File C:\dev\Photo Studio\Photo Studio\Source\Layer.cpp
;	COMDAT ??1Layer@@QEAA@XZ
_TEXT	SEGMENT
this$ = 48
??1Layer@@QEAA@XZ PROC					; Layer::~Layer, COMDAT

; 26   : {

$LN42:
	push	rbx
	sub	rsp, 32					; 00000020H
	mov	rbx, rcx
; File C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.36.32532\include\xstring

; 2282 :         return _BUF_SIZE <= _Myres;

	mov	rdx, QWORD PTR [rcx+80]

; 4868 :         if (_My_data._Large_string_engaged()) {

	cmp	rdx, 16
	jb	SHORT $LN15@Layer

; 4869 :             _ASAN_STRING_REMOVE(*this);
; 4870 :             const pointer _Ptr = _My_data._Bx._Ptr;

	mov	rcx, QWORD PTR [rcx+56]

; 4871 :             auto& _Al          = _Getal();
; 4872 :             _Destroy_in_place(_My_data._Bx._Ptr);
; 4873 :             _My_data._Activate_SSO_buffer();
; 4874 :             _Al.deallocate(_Ptr, _My_data._Myres + 1);

	inc	rdx
; File C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.36.32532\include\xmemory

; 251  :         if (_Bytes >= _Big_allocation_threshold) { // boost the alignment of big allocations to help autovectorization

	cmp	rdx, 4096				; 00001000H
	jb	SHORT $LN27@Layer

; 147  :     _Bytes += _Non_user_size;

	add	rdx, 39					; 00000027H

; 148  : 
; 149  :     const uintptr_t* const _Ptr_user = static_cast<uintptr_t*>(_Ptr);
; 150  :     const uintptr_t _Ptr_container   = _Ptr_user[-1];

	mov	r8, QWORD PTR [rcx-8]

; 151  : 
; 152  :     // If the following asserts, it likely means that we are performing
; 153  :     // an aligned delete on memory coming from an unaligned allocation.
; 154  :     _STL_ASSERT(_Ptr_user[-2] == _Big_allocation_sentinel, "invalid argument");
; 155  : 
; 156  :     // Extra paranoia on aligned allocation/deallocation; ensure _Ptr_container is
; 157  :     // in range [_Min_back_shift, _Non_user_size]
; 158  : #ifdef _DEBUG
; 159  :     constexpr uintptr_t _Min_back_shift = 2 * sizeof(void*);
; 160  : #else // ^^^ _DEBUG / !_DEBUG vvv
; 161  :     constexpr uintptr_t _Min_back_shift = sizeof(void*);
; 162  : #endif // _DEBUG
; 163  :     const uintptr_t _Back_shift = reinterpret_cast<uintptr_t>(_Ptr) - _Ptr_container;

	sub	rcx, r8

; 164  :     _STL_VERIFY(_Back_shift >= _Min_back_shift && _Back_shift <= _Non_user_size, "invalid argument");

	lea	rax, QWORD PTR [rcx-8]
	cmp	rax, 31
	ja	SHORT $LN24@Layer

; 165  :     _Ptr = reinterpret_cast<void*>(_Ptr_container);

	mov	rcx, r8
$LN27@Layer:

; 255  :         ::operator delete(_Ptr, _Bytes);

	call	??3@YAXPEAX_K@Z				; operator delete
$LN15@Layer:
; File C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.36.32532\include\xstring

; 4877 :         _My_data._Mysize = 0;

	mov	QWORD PTR [rbx+72], 0

; 4878 :         _My_data._Myres  = _BUF_SIZE - 1;

	mov	QWORD PTR [rbx+80], 15

; 4879 :         // the _Traits::assign is last so the codegen doesn't think the char write can alias this
; 4880 :         _Traits::assign(_My_data._Bx._Buf[0], _Elem());

	mov	BYTE PTR [rbx+56], 0
; File C:\dev\Photo Studio\Photo Studio\Source\Framebuffer.cpp

; 30   : 	glDeleteRenderbuffers(1, &m_RBO);

	lea	rdx, QWORD PTR [rbx+20]
	mov	ecx, 1
	call	QWORD PTR glad_glDeleteRenderbuffers

; 31   : 	glDeleteFramebuffers(1, &m_FBO);

	lea	rdx, QWORD PTR [rbx+16]
	mov	ecx, 1
	call	QWORD PTR glad_glDeleteFramebuffers
	npad	1
; File C:\dev\Photo Studio\Photo Studio\Source\Texture.cpp

; 10   : 	glDeleteTextures(1, &m_ID);

	lea	rdx, QWORD PTR [rbx+24]
	mov	ecx, 1
	call	QWORD PTR glad_glDeleteTextures
	npad	1
; File C:\dev\Photo Studio\Photo Studio\Source\Layer.cpp

; 28   : }

	add	rsp, 32					; 00000020H
	pop	rbx
	ret	0
$LN24@Layer:
; File C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.36.32532\include\xmemory

; 164  :     _STL_VERIFY(_Back_shift >= _Min_back_shift && _Back_shift <= _Non_user_size, "invalid argument");

	call	QWORD PTR __imp__invalid_parameter_noinfo_noreturn
	int	3
$LN39@Layer:
??1Layer@@QEAA@XZ ENDP					; Layer::~Layer
_TEXT	ENDS
END
