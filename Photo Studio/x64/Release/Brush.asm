; Listing generated by Microsoft (R) Optimizing Compiler Version 19.36.32535.0 

include listing.inc

INCLUDELIB OLDNAMES

PUBLIC	??_C@_05PDOBBJNA@Color@				; `string'
PUBLIC	??_C@_0L@CKCKKFCJ@Brush?5tool@			; `string'
EXTRN	_Init_thread_header:PROC
EXTRN	_Init_thread_footer:PROC
EXTRN	_Init_thread_epoch:DWORD
;	COMDAT ?flags@?1??DrawPaintbrushMenu@Brush@@QEAAXXZ@4HA
_BSS	SEGMENT
?flags@?1??DrawPaintbrushMenu@Brush@@QEAAXXZ@4HA DD 01H DUP (?) ; `Brush::DrawPaintbrushMenu'::`2'::flags
_BSS	ENDS
;	COMDAT ?Pressed@?1??DrawInterpolatedPaintbrush@Brush@@QEAAXM@Z@4_NA
_DATA	SEGMENT
?Pressed@?1??DrawInterpolatedPaintbrush@Brush@@QEAAXM@Z@4_NA DB 01H ; `Brush::DrawInterpolatedPaintbrush'::`2'::Pressed
_DATA	ENDS
;	COMDAT ??_C@_0L@CKCKKFCJ@Brush?5tool@
CONST	SEGMENT
??_C@_0L@CKCKKFCJ@Brush?5tool@ DB 'Brush tool', 00H	; `string'
CONST	ENDS
;	COMDAT ??_C@_05PDOBBJNA@Color@
CONST	SEGMENT
??_C@_05PDOBBJNA@Color@ DB 'Color', 00H			; `string'
PUBLIC	??$?DM$0A@@glm@@YA?AU?$vec@$02M$0A@@0@AEBU10@0@Z ; glm::operator*<float,0>
PUBLIC	?call@?$compute_dot@U?$vec@$02M$0A@@glm@@M$0A@@detail@glm@@SAMAEBU?$vec@$02M$0A@@3@0@Z ; glm::detail::compute_dot<glm::vec<3,float,0>,float,0>::call
PUBLIC	??$dot@$02M$0A@@glm@@YAMAEBU?$vec@$02M$0A@@0@0@Z ; glm::dot<3,float,0>
PUBLIC	?call@?$compute_length@$02M$0A@$0A@@detail@glm@@SAMAEBU?$vec@$02M$0A@@3@@Z ; glm::detail::compute_length<3,float,0,0>::call
PUBLIC	??$?0MMMN@?$vec@$03M$0A@@glm@@QEAA@MMMN@Z	; glm::vec<4,float,0>::vec<4,float,0><float,float,float,double>
PUBLIC	??$length@$02M$0A@@glm@@YAMAEBU?$vec@$02M$0A@@0@@Z ; glm::length<3,float,0>
PUBLIC	??$?GM$0A@@glm@@YA?AU?$vec@$02M$0A@@0@AEBU10@0@Z ; glm::operator-<float,0>
PUBLIC	?DrawPaintbrushMenu@Brush@@QEAAXXZ		; Brush::DrawPaintbrushMenu
PUBLIC	?DrawPencil@Brush@@AEAAXU?$vec@$02M$0A@@glm@@M@Z ; Brush::DrawPencil
PUBLIC	?DrawInterpolatedPaintbrush@Brush@@QEAAXM@Z	; Brush::DrawInterpolatedPaintbrush
PUBLIC	??1Brush@@QEAA@XZ				; Brush::~Brush
PUBLIC	??0Brush@@QEAA@XZ				; Brush::Brush
PUBLIC	?sqrt@@YAMM@Z					; sqrt
;	COMDAT ?PreviousPosition@?1??DrawInterpolatedPaintbrush@Brush@@QEAAXM@Z@4U?$vec@$02M$0A@@glm@@A
_BSS	SEGMENT
?PreviousPosition@?1??DrawInterpolatedPaintbrush@Brush@@QEAAXM@Z@4U?$vec@$02M$0A@@glm@@A DB 0cH DUP (?) ; `Brush::DrawInterpolatedPaintbrush'::`2'::PreviousPosition
_BSS	ENDS
;	COMDAT ?$TSS0@?1??DrawInterpolatedPaintbrush@Brush@@QEAAXM@Z@4HA
_BSS	SEGMENT
?$TSS0@?1??DrawInterpolatedPaintbrush@Brush@@QEAAXM@Z@4HA DD 01H DUP (?) ; `Brush::DrawInterpolatedPaintbrush'::`2'::$TSS0
_BSS	ENDS
;	COMDAT ?$TSS1@?1??DrawInterpolatedPaintbrush@Brush@@QEAAXM@Z@4HA
_BSS	SEGMENT
?$TSS1@?1??DrawInterpolatedPaintbrush@Brush@@QEAAXM@Z@4HA DD 01H DUP (?) ; `Brush::DrawInterpolatedPaintbrush'::`2'::$TSS1
_BSS	ENDS
;	COMDAT ?PreviousDrawnPosition@?1??DrawInterpolatedPaintbrush@Brush@@QEAAXM@Z@4U?$vec@$02M$0A@@glm@@A
_BSS	SEGMENT
?PreviousDrawnPosition@?1??DrawInterpolatedPaintbrush@Brush@@QEAAXM@Z@4U?$vec@$02M$0A@@glm@@A DB 0cH DUP (?) ; `Brush::DrawInterpolatedPaintbrush'::`2'::PreviousDrawnPosition
_BSS	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$?DrawPaintbrushMenu@Brush@@QEAAXXZ DD imagerel $LN12@DrawPaintb
	DD	imagerel $LN12@DrawPaintb+226
	DD	imagerel $unwind$?DrawPaintbrushMenu@Brush@@QEAAXXZ
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$?DrawPencil@Brush@@AEAAXU?$vec@$02M$0A@@glm@@M@Z DD imagerel $LN145@DrawPencil
	DD	imagerel $LN145@DrawPencil+363
	DD	imagerel $unwind$?DrawPencil@Brush@@AEAAXU?$vec@$02M$0A@@glm@@M@Z
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$?DrawInterpolatedPaintbrush@Brush@@QEAAXM@Z DD imagerel $LN729@DrawInterp
	DD	imagerel $LN729@DrawInterp+1819
	DD	imagerel $unwind$?DrawInterpolatedPaintbrush@Brush@@QEAAXM@Z
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$??1Brush@@QEAA@XZ DD imagerel $LN11@Brush
	DD	imagerel $LN11@Brush+34
	DD	imagerel $unwind$??1Brush@@QEAA@XZ
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$??0Brush@@QEAA@XZ DD imagerel $LN6@Brush
	DD	imagerel $LN6@Brush+43
	DD	imagerel $unwind$??0Brush@@QEAA@XZ
;	COMDAT xdata
xdata	SEGMENT
$unwind$??0Brush@@QEAA@XZ DQ 03002320600020601r	; 1.96423e-77
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$ip2state$??1Brush@@QEAA@XZ DW 01802H
	DB	02H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$stateUnwindMap$??1Brush@@QEAA@XZ DW 0e02H
	DD	imagerel __std_terminate
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$cppxdata$??1Brush@@QEAA@XZ DB 068H
	DD	imagerel $stateUnwindMap$??1Brush@@QEAA@XZ
	DD	imagerel $ip2state$??1Brush@@QEAA@XZ
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$??1Brush@@QEAA@XZ DQ 03002320600020619r	; 1.96423e-77
	DD	imagerel __CxxFrameHandler4
	DD	imagerel $cppxdata$??1Brush@@QEAA@XZ
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$ip2state$?DrawInterpolatedPaintbrush@Brush@@QEAAXM@Z DQ 0360203c500075912r ; 1.54077e-48
	DQ	004e8003004048900r		; 5.04381e-285
	DD	04e90068H
	DW	04c02H
	DB	00H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$stateUnwindMap$?DrawInterpolatedPaintbrush@Brush@@QEAAXM@Z DW 0a04H
	DD	imagerel ??1?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAA@XZ
	DW	03aa0H
	DD	imagerel ??1?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAA@XZ
	DW	0241H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$cppxdata$?DrawInterpolatedPaintbrush@Brush@@QEAAXM@Z DB 028H
	DD	imagerel $stateUnwindMap$?DrawInterpolatedPaintbrush@Brush@@QEAAXM@Z
	DD	imagerel $ip2state$?DrawInterpolatedPaintbrush@Brush@@QEAAXM@Z
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?DrawInterpolatedPaintbrush@Brush@@QEAAXM@Z DQ 00012d84b00194b11r ; 2.62071e-308
	DQ	00014b83b0013c843r		; 2.88142e-308
	DQ	00016982e0015a833r		; 3.14215e-308
	DQ	00018782400178829r		; 3.40287e-308
	DQ	0003c341c00196820r		; 1.56887e-307
	DQ	0e00cf00e0034011cr		; -4.84989e+154
	DQ	0000050086009700ar		; 4.34762e-310
	DD	imagerel __CxxFrameHandler4
	DD	imagerel $cppxdata$?DrawInterpolatedPaintbrush@Brush@@QEAAXM@Z
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$ip2state$?DrawPencil@Brush@@AEAAXU?$vec@$02M$0A@@glm@@M@Z DD 0202f504H
	DW	030H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$stateUnwindMap$?DrawPencil@Brush@@AEAAXU?$vec@$02M$0A@@glm@@M@Z DW 0a02H
	DD	imagerel ??1?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAA@XZ
	DB	040H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$cppxdata$?DrawPencil@Brush@@AEAAXU?$vec@$02M$0A@@glm@@M@Z DB 028H
	DD	imagerel $stateUnwindMap$?DrawPencil@Brush@@AEAAXU?$vec@$02M$0A@@glm@@M@Z
	DD	imagerel $ip2state$?DrawPencil@Brush@@AEAAXU?$vec@$02M$0A@@glm@@M@Z
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?DrawPencil@Brush@@AEAAXU?$vec@$02M$0A@@glm@@M@Z DQ 00022010900030911r ; 5.00754e-308
	DD	03002H
	DD	imagerel __CxxFrameHandler4
	DD	imagerel $cppxdata$?DrawPencil@Brush@@AEAAXU?$vec@$02M$0A@@glm@@M@Z
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?DrawPaintbrushMenu@Brush@@QEAAXXZ DQ 03002b20600021519r ; 2.01821e-77
	DD	imagerel __GSHandlerCheck
	DD	050H
END
