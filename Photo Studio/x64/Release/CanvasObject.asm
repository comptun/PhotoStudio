; Listing generated by Microsoft (R) Optimizing Compiler Version 19.36.32535.0 

include listing.inc

INCLUDELIB OLDNAMES

PUBLIC	?size@?$vector@IV?$allocator@I@std@@@std@@QEBA_KXZ ; std::vector<unsigned int,std::allocator<unsigned int> >::size
PUBLIC	?front@?$vector@IV?$allocator@I@std@@@std@@QEAAAEAIXZ ; std::vector<unsigned int,std::allocator<unsigned int> >::front
PUBLIC	?size@?$vector@MV?$allocator@M@std@@@std@@QEBA_KXZ ; std::vector<float,std::allocator<float> >::size
PUBLIC	?front@?$vector@MV?$allocator@M@std@@@std@@QEAAAEAMXZ ; std::vector<float,std::allocator<float> >::front
PUBLIC	?Draw@CanvasObject@@QEAAXXZ			; CanvasObject::Draw
PUBLIC	??0CanvasObject@@QEAA@V?$vector@IV?$allocator@I@std@@@std@@V?$vector@MV?$allocator@M@std@@@2@@Z ; CanvasObject::CanvasObject
PUBLIC	??1CanvasObject@@QEAA@XZ			; CanvasObject::~CanvasObject
;	COMDAT pdata
pdata	SEGMENT
$pdata$?Draw@CanvasObject@@QEAAXXZ DD imagerel $LN7@Draw
	DD	imagerel $LN7@Draw+62
	DD	imagerel $unwind$?Draw@CanvasObject@@QEAAXXZ
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$??0CanvasObject@@QEAA@V?$vector@IV?$allocator@I@std@@@std@@V?$vector@MV?$allocator@M@std@@@2@@Z DD imagerel $LN67@CanvasObje
	DD	imagerel $LN67@CanvasObje+507
	DD	imagerel $unwind$??0CanvasObject@@QEAA@V?$vector@IV?$allocator@I@std@@@std@@V?$vector@MV?$allocator@M@std@@@2@@Z
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$??1CanvasObject@@QEAA@XZ DD imagerel $LN65@CanvasObje
	DD	imagerel $LN65@CanvasObje+173
	DD	imagerel $unwind$??1CanvasObject@@QEAA@XZ
;	COMDAT xdata
xdata	SEGMENT
$unwind$??1CanvasObject@@QEAA@XZ DQ 00007340a00040a01r ; 1.00174e-308
	DD	07006320aH
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$ip2state$??0CanvasObject@@QEAA@V?$vector@IV?$allocator@I@std@@@std@@V?$vector@MV?$allocator@M@std@@@2@@Z DQ 08d081c061a04760ar ; -6.89638e-246
	DD	026d0203H
	DB	00H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$stateUnwindMap$??0CanvasObject@@QEAA@V?$vector@IV?$allocator@I@std@@@std@@V?$vector@MV?$allocator@M@std@@@2@@Z DW 0c08H
	DD	imagerel ??1?$vector@MV?$allocator@M@std@@@std@@QEAA@XZ
	DW	03480H
	DD	imagerel ??1?$vector@IV?$allocator@I@std@@@std@@QEAA@XZ
	DW	03670H
	DD	imagerel ?dtor$2@?0???0CanvasObject@@QEAA@V?$vector@IV?$allocator@I@std@@@std@@V?$vector@MV?$allocator@M@std@@@2@@Z@4HA
	DB	02eH
	DD	imagerel ?dtor$3@?0???0CanvasObject@@QEAA@V?$vector@IV?$allocator@I@std@@@std@@V?$vector@MV?$allocator@M@std@@@2@@Z@4HA
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$cppxdata$??0CanvasObject@@QEAA@V?$vector@IV?$allocator@I@std@@@std@@V?$vector@MV?$allocator@M@std@@@2@@Z DB 028H
	DD	imagerel $stateUnwindMap$??0CanvasObject@@QEAA@V?$vector@IV?$allocator@I@std@@@std@@V?$vector@MV?$allocator@M@std@@@2@@Z
	DD	imagerel $ip2state$??0CanvasObject@@QEAA@V?$vector@IV?$allocator@I@std@@@std@@V?$vector@MV?$allocator@M@std@@@2@@Z
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$??0CanvasObject@@QEAA@V?$vector@IV?$allocator@I@std@@@std@@V?$vector@MV?$allocator@M@std@@@2@@Z DQ 00013341000081f19r ; 2.67056e-308
	DQ	07008e00af00c9210r		; 4.82739e+231
	DD	050066007H
	DD	imagerel __GSHandlerCheck_EH4
	DD	imagerel $cppxdata$??0CanvasObject@@QEAA@V?$vector@IV?$allocator@I@std@@@std@@V?$vector@MV?$allocator@M@std@@@2@@Z
	DD	04aH
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?Draw@CanvasObject@@QEAAXXZ DQ 03002320600020601r ; 1.96423e-77
END
