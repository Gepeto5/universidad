#################################################
# ESTRUCTURA DE COMPUTADORES
# Interpolacion lineal
# Autor: Luis Rincon Corcoles
#################################################
# Declaracion de variables y tiras de caracteres
#################################################
	.data
x:	.space		4
y:	.space		4
x1:	.space		4
y1:	.space		4
x2:	.space		4
y2:	.space		4
tira1:	.asciiz		"Introduzca la coordenada X del primer punto conocido: "
tira2:	.asciiz		"Introduzca la coordenada Y del primer punto conocido: "
tira3:	.asciiz		"Introduzca la coordenada X del segundo punto conocido: "
tira4:	.asciiz		"Introduzca la coordenada Y del segundo punto conocido: "
tira5:	.asciiz		"Introduzca la coordenada X del punto que se desea interpolar: "
tira6:	.asciiz		"El valor estimado de y en ese punto es: "

#################################################
# Implementacion del programa
#################################################
        .text
# printf("Introduzca la coordenada X del primer punto conocido: ");
        li      $v0,4
        la      $a0,tira1
        syscall
# scanf("%d",&x1);
        li      $v0,5
        syscall
        sw      $v0,x1
# printf("Introduzca la coordenada Y del primer punto conocido: ");
        li      $v0,4
        la      $a0,tira2
        syscall
# scanf("%d",&y1);
        li      $v0,5
        syscall
        sw      $v0,y1
# printf("Introduzca la coordenada X del segundo punto conocido: ");
        li      $v0,4
        la      $a0,tira3
        syscall
# scanf("%d",&x2);
        li      $v0,5
        syscall
        sw      $v0,x2
# printf("Introduzca la coordenada Y del segundo punto conocido: ");
        li      $v0,4
        la      $a0,tira4
        syscall
# scanf("%d",&y2);
        li      $v0,5
        syscall
        sw      $v0,y2
# printf("Introduzca la coordenada X del punto que se desea interpolar: ");
        li      $v0,4
        la      $a0,tira5
        syscall
# scanf("%d",&x);
        li      $v0,5
        syscall
        sw      $v0,x
# y = ((x-x1)*(y2-y1)) DIV (x2-x1) + y1;
        lw      $s0,x          # Carga de x en $s0
        lw      $s1,x1         # Carga de x1 en $s1
        lw      $s2,y1         # Carga de y1 en $s2
        lw      $s3,x2         # Carga de x2 en $s3
        lw      $s4,y2         # Carga de y2 en $s4
        sub     $t0,$s0,$s1    # t0 = x - x1
        sub     $t1,$s4,$s2    # t1 = y2 - y1
        mul     $t0,$t0,$t1    # t0 = t0*t1
        sub     $t1,$s3,$s1    # t1 = x2 - x1
        div     $t0,$t0,$t1    # t0 = t0 / t1
        add     $t0,$t0,$s2    # t0 = t0 + y1
        sw      $t0,y          # Almacenamiento del resultado en y
# printf("El valor estimado de y en ese punto es: %d\n",y);
        li      $v0,4
        la      $a0,tira6
        syscall
        li      $v0,1
        lw      $a0,y
        syscall
# Fin del programa
        li      $v0,17
        li      $a0,0
        syscall
