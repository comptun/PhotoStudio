; Listing generated by Microsoft (R) Optimizing Compiler Version 19.36.32535.0 

include listing.inc

INCLUDELIB OLDNAMES

PUBLIC	??_C@_0BD@BJOEHOL@imgui_impl_opengl2@		; `string'
EXTRN	__imp_glGetIntegerv:PROC
EXTRN	__imp_glPushAttrib:PROC
EXTRN	__imp_glOrtho:PROC
EXTRN	__imp_glPixelStorei:PROC
EXTRN	__imp_glShadeModel:PROC
EXTRN	__imp_glPushMatrix:PROC
EXTRN	__imp_glDisable:PROC
EXTRN	__imp_glDrawElements:PROC
EXTRN	__imp_glTexEnvi:PROC
EXTRN	__imp_glColorPointer:PROC
EXTRN	__imp_glTexImage2D:PROC
EXTRN	__imp_glClearColor:PROC
EXTRN	__imp_glGetTexEnviv:PROC
EXTRN	__imp_glTexCoordPointer:PROC
EXTRN	__imp_glDeleteTextures:PROC
EXTRN	__imp_glTexParameteri:PROC
EXTRN	__imp_glLoadIdentity:PROC
EXTRN	__imp_glBlendFunc:PROC
EXTRN	__imp_glMatrixMode:PROC
EXTRN	__imp_glDisableClientState:PROC
EXTRN	__imp_glScissor:PROC
EXTRN	__imp_glEnable:PROC
EXTRN	__imp_glVertexPointer:PROC
EXTRN	__imp_glGenTextures:PROC
EXTRN	__imp_glBindTexture:PROC
EXTRN	__imp_glPolygonMode:PROC
EXTRN	__imp_glPopAttrib:PROC
EXTRN	__imp_glClear:PROC
EXTRN	__imp_glEnableClientState:PROC
EXTRN	__imp_glViewport:PROC
EXTRN	__imp_glPopMatrix:PROC
;	COMDAT ??_C@_0BD@BJOEHOL@imgui_impl_opengl2@
CONST	SEGMENT
??_C@_0BD@BJOEHOL@imgui_impl_opengl2@ DB 'imgui_impl_opengl2', 00H ; `string'
PUBLIC	??$IM_DELETE@UImGui_ImplOpenGL2_Data@@@@YAXPEAUImGui_ImplOpenGL2_Data@@@Z ; IM_DELETE<ImGui_ImplOpenGL2_Data>
PUBLIC	??A?$ImVector@UImDrawCmd@@@@QEBAAEBUImDrawCmd@@H@Z ; ImVector<ImDrawCmd>::operator[]
PUBLIC	??A?$ImVector@PEAUImDrawList@@@@QEAAAEAPEAUImDrawList@@H@Z ; ImVector<ImDrawList *>::operator[]
PUBLIC	?ImGui_ImplOpenGL2_DestroyDeviceObjects@@YAXXZ	; ImGui_ImplOpenGL2_DestroyDeviceObjects
PUBLIC	?ImGui_ImplOpenGL2_CreateDeviceObjects@@YA_NXZ	; ImGui_ImplOpenGL2_CreateDeviceObjects
PUBLIC	?ImGui_ImplOpenGL2_DestroyFontsTexture@@YAXXZ	; ImGui_ImplOpenGL2_DestroyFontsTexture
PUBLIC	?ImGui_ImplOpenGL2_CreateFontsTexture@@YA_NXZ	; ImGui_ImplOpenGL2_CreateFontsTexture
PUBLIC	??0ImGui_ImplOpenGL2_Data@@QEAA@XZ		; ImGui_ImplOpenGL2_Data::ImGui_ImplOpenGL2_Data
PUBLIC	?SetTexID@ImFontAtlas@@QEAAXPEAX@Z		; ImFontAtlas::SetTexID
PUBLIC	?GetTexID@ImDrawCmd@@QEBAPEAXXZ			; ImDrawCmd::GetTexID
PUBLIC	??3@YAXPEAXUImNewWrapper@@0@Z			; operator delete
PUBLIC	??2@YAPEAX_KUImNewWrapper@@PEAX@Z		; operator new
PUBLIC	?ImGui_ImplOpenGL2_Shutdown@@YAXXZ		; ImGui_ImplOpenGL2_Shutdown
PUBLIC	?ImGui_ImplOpenGL2_Init@@YA_NXZ			; ImGui_ImplOpenGL2_Init
PUBLIC	?ImGui_ImplOpenGL2_RenderDrawData@@YAXPEAUImDrawData@@@Z ; ImGui_ImplOpenGL2_RenderDrawData
PUBLIC	?ImGui_ImplOpenGL2_NewFrame@@YAXXZ		; ImGui_ImplOpenGL2_NewFrame
;	COMDAT pdata
pdata	SEGMENT
$pdata$?ImGui_ImplOpenGL2_ShutdownPlatformInterface@@YAXXZ DD imagerel ?ImGui_ImplOpenGL2_ShutdownPlatformInterface@@YAXXZ
	DD	imagerel ?ImGui_ImplOpenGL2_ShutdownPlatformInterface@@YAXXZ+68
	DD	imagerel $unwind$?ImGui_ImplOpenGL2_ShutdownPlatformInterface@@YAXXZ
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$?ImGui_ImplOpenGL2_RenderWindow@@YAXPEAUImGuiViewport@@PEAX@Z DD imagerel ?ImGui_ImplOpenGL2_RenderWindow@@YAXPEAUImGuiViewport@@PEAX@Z
	DD	imagerel ?ImGui_ImplOpenGL2_RenderWindow@@YAXPEAUImGuiViewport@@PEAX@Z+66
	DD	imagerel $unwind$?ImGui_ImplOpenGL2_RenderWindow@@YAXPEAUImGuiViewport@@PEAX@Z
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$?ImGui_ImplOpenGL2_DestroyDeviceObjects@@YAXXZ DD imagerel $LN13@ImGui_Impl
	DD	imagerel $LN13@ImGui_Impl+81
	DD	imagerel $unwind$?ImGui_ImplOpenGL2_DestroyDeviceObjects@@YAXXZ
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$?ImGui_ImplOpenGL2_CreateDeviceObjects@@YA_NXZ DD imagerel $LN11@ImGui_Impl
	DD	imagerel $LN11@ImGui_Impl+292
	DD	imagerel $unwind$?ImGui_ImplOpenGL2_CreateDeviceObjects@@YA_NXZ
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$?ImGui_ImplOpenGL2_DestroyFontsTexture@@YAXXZ DD imagerel $LN11@ImGui_Impl
	DD	imagerel $LN11@ImGui_Impl+81
	DD	imagerel $unwind$?ImGui_ImplOpenGL2_DestroyFontsTexture@@YAXXZ
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$?ImGui_ImplOpenGL2_CreateFontsTexture@@YA_NXZ DD imagerel $LN9@ImGui_Impl
	DD	imagerel $LN9@ImGui_Impl+292
	DD	imagerel $unwind$?ImGui_ImplOpenGL2_CreateFontsTexture@@YA_NXZ
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$?ImGui_ImplOpenGL2_SetupRenderState@@YAXPEAUImDrawData@@HH@Z DD imagerel ?ImGui_ImplOpenGL2_SetupRenderState@@YAXPEAUImDrawData@@HH@Z
	DD	imagerel ?ImGui_ImplOpenGL2_SetupRenderState@@YAXPEAUImDrawData@@HH@Z+349
	DD	imagerel $unwind$?ImGui_ImplOpenGL2_SetupRenderState@@YAXPEAUImDrawData@@HH@Z
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$?ImGui_ImplOpenGL2_Shutdown@@YAXXZ DD imagerel $LN54@ImGui_Impl
	DD	imagerel $LN54@ImGui_Impl+317
	DD	imagerel $unwind$?ImGui_ImplOpenGL2_Shutdown@@YAXXZ
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$?ImGui_ImplOpenGL2_Init@@YA_NXZ DD imagerel $LN30@ImGui_Impl
	DD	imagerel $LN30@ImGui_Impl+212
	DD	imagerel $unwind$?ImGui_ImplOpenGL2_Init@@YA_NXZ
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$?ImGui_ImplOpenGL2_RenderDrawData@@YAXPEAUImDrawData@@@Z DD imagerel $LN43@ImGui_Impl
	DD	imagerel $LN43@ImGui_Impl+82
	DD	imagerel $unwind$?ImGui_ImplOpenGL2_RenderDrawData@@YAXPEAUImDrawData@@@Z
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$4$?ImGui_ImplOpenGL2_RenderDrawData@@YAXPEAUImDrawData@@@Z DD imagerel $LN43@ImGui_Impl+82
	DD	imagerel $LN43@ImGui_Impl+274
	DD	imagerel $chain$4$?ImGui_ImplOpenGL2_RenderDrawData@@YAXPEAUImDrawData@@@Z
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$8$?ImGui_ImplOpenGL2_RenderDrawData@@YAXPEAUImDrawData@@@Z DD imagerel $LN43@ImGui_Impl+274
	DD	imagerel $LN43@ImGui_Impl+729
	DD	imagerel $chain$8$?ImGui_ImplOpenGL2_RenderDrawData@@YAXPEAUImDrawData@@@Z
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$9$?ImGui_ImplOpenGL2_RenderDrawData@@YAXPEAUImDrawData@@@Z DD imagerel $LN43@ImGui_Impl+729
	DD	imagerel $LN43@ImGui_Impl+968
	DD	imagerel $chain$9$?ImGui_ImplOpenGL2_RenderDrawData@@YAXPEAUImDrawData@@@Z
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$10$?ImGui_ImplOpenGL2_RenderDrawData@@YAXPEAUImDrawData@@@Z DD imagerel $LN43@ImGui_Impl+968
	DD	imagerel $LN43@ImGui_Impl+995
	DD	imagerel $chain$10$?ImGui_ImplOpenGL2_RenderDrawData@@YAXPEAUImDrawData@@@Z
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$?ImGui_ImplOpenGL2_NewFrame@@YAXXZ DD imagerel $LN20@ImGui_Impl
	DD	imagerel $LN20@ImGui_Impl+53
	DD	imagerel $unwind$?ImGui_ImplOpenGL2_NewFrame@@YAXXZ
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$0$?ImGui_ImplOpenGL2_NewFrame@@YAXXZ DD imagerel $LN20@ImGui_Impl+53
	DD	imagerel $LN20@ImGui_Impl+300
	DD	imagerel $chain$0$?ImGui_ImplOpenGL2_NewFrame@@YAXXZ
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$1$?ImGui_ImplOpenGL2_NewFrame@@YAXXZ DD imagerel $LN20@ImGui_Impl+300
	DD	imagerel $LN20@ImGui_Impl+319
	DD	imagerel $chain$1$?ImGui_ImplOpenGL2_NewFrame@@YAXXZ
;	COMDAT xdata
xdata	SEGMENT
$chain$1$?ImGui_ImplOpenGL2_NewFrame@@YAXXZ DD 021H
	DD	imagerel $LN20@ImGui_Impl
	DD	imagerel $LN20@ImGui_Impl+53
	DD	imagerel $unwind$?ImGui_ImplOpenGL2_NewFrame@@YAXXZ
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$chain$0$?ImGui_ImplOpenGL2_NewFrame@@YAXXZ DQ 00010740800020821r ; 2.28811e-308
	DD	imagerel $LN20@ImGui_Impl
	DD	imagerel $LN20@ImGui_Impl+53
	DD	imagerel $unwind$?ImGui_ImplOpenGL2_NewFrame@@YAXXZ
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?ImGui_ImplOpenGL2_NewFrame@@YAXXZ DQ 03002d20600021519r ; 2.0317e-77
	DD	imagerel __GSHandlerCheck
	DD	068H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$chain$10$?ImGui_ImplOpenGL2_RenderDrawData@@YAXPEAUImDrawData@@@Z DD 021H
	DD	imagerel $LN43@ImGui_Impl
	DD	imagerel $LN43@ImGui_Impl+82
	DD	imagerel $unwind$?ImGui_ImplOpenGL2_RenderDrawData@@YAXPEAUImDrawData@@@Z
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$chain$9$?ImGui_ImplOpenGL2_RenderDrawData@@YAXPEAUImDrawData@@@Z DD 021H
	DD	imagerel $LN43@ImGui_Impl+82
	DD	imagerel $LN43@ImGui_Impl+274
	DD	imagerel $chain$4$?ImGui_ImplOpenGL2_RenderDrawData@@YAXPEAUImDrawData@@@Z
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$chain$8$?ImGui_ImplOpenGL2_RenderDrawData@@YAXPEAUImDrawData@@@Z DQ 00019742200082221r ; 3.53976e-308
	DQ	0002054120021641ar		; 4.54149e-308
	DD	01f3408H
	DD	imagerel $LN43@ImGui_Impl+82
	DD	imagerel $LN43@ImGui_Impl+274
	DD	imagerel $chain$4$?ImGui_ImplOpenGL2_RenderDrawData@@YAXPEAUImDrawData@@@Z
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$chain$4$?ImGui_ImplOpenGL2_RenderDrawData@@YAXPEAUImDrawData@@@Z DQ 000089822000a2221r ; 1.19518e-308
	DQ	0000a78180009881dr		; 1.45591e-308
	DQ	00018d404000b680er		; 3.45278e-308
	DD	imagerel $LN43@ImGui_Impl
	DD	imagerel $LN43@ImGui_Impl+82
	DD	imagerel $unwind$?ImGui_ImplOpenGL2_RenderDrawData@@YAXPEAUImDrawData@@@Z
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?ImGui_ImplOpenGL2_RenderDrawData@@YAXPEAUImDrawData@@@Z DQ 0001a011000051f19r ; 3.61632e-308
	DQ	00000c005e007f009r		; 1.04313e-309
	DD	imagerel __GSHandlerCheck
	DD	070H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?ImGui_ImplOpenGL2_Init@@YA_NXZ DQ 03002320600020601r ; 1.96423e-77
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?ImGui_ImplOpenGL2_Shutdown@@YAXXZ DQ 0000a6418000a1801r ; 1.44505e-308
	DQ	00008341800095418r		; 1.14084e-308
	DQ	07010e012f0143218r		; 6.5498e+231
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?ImGui_ImplOpenGL2_SetupRenderState@@YAXPEAUImDrawData@@HH@Z DQ 00009640f00060f01r ; 1.30596e-308
	DQ	0700b520f0008340fr		; 5.30195e+231
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?ImGui_ImplOpenGL2_CreateFontsTexture@@YA_NXZ DQ 00010340a00041919r ; 2.25334e-308
	DD	07006d20aH
	DD	imagerel __GSHandlerCheck
	DD	068H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?ImGui_ImplOpenGL2_DestroyFontsTexture@@YAXXZ DQ 00006340a00040a01r ; 8.62672e-309
	DD	07006320aH
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?ImGui_ImplOpenGL2_CreateDeviceObjects@@YA_NXZ DQ 00010340a00041919r ; 2.25334e-308
	DD	07006d20aH
	DD	imagerel __GSHandlerCheck
	DD	068H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?ImGui_ImplOpenGL2_DestroyDeviceObjects@@YAXXZ DQ 00006340a00040a01r ; 8.62672e-309
	DD	07006320aH
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?ImGui_ImplOpenGL2_RenderWindow@@YAXPEAUImGuiViewport@@PEAX@Z DQ 03002320600020601r ; 1.96423e-77
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?ImGui_ImplOpenGL2_ShutdownPlatformInterface@@YAXXZ DQ 00006340a00040a01r ; 8.62672e-309
	DD	07006320aH
END
