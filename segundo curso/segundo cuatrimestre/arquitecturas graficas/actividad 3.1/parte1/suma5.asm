	.data
A:	.space	4      # Copia en $s1
B:	.space	4      # Copia en $s2
C:	.space	4      # Copia en $s3
	.text
if:	lw	$s2,B
	lw	$s3,C
	beq	$s2,$s3,then
else:	sub	$s1,$s2,$s3
	sw	$s1,A
	j	endif
then:	lw	$s1,A
	add	$s1,$s1,$s2
	sw	$s1,A
endif:
