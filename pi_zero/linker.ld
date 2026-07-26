SECTIONS {
	. = 0x8000;

	.text : {
		*(.text.boot)
		*(.text)
	}

	.data : { *(.data) }
	.bss : { *(.bss) }
}
