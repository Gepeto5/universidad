select * from COSTS;
--create table prueba(a varchar(4), b varchar(4), primary key(a,b));

--hay que crear tablas grupo y alumno en oracle icluyendo las restricciones
--hay que insertar 3 filas en cada una e intentar violar las restricciones

--2- hay que modificar el diseño para que un alumno pertenezca a varios grupos

create table grupo(
  cod_grupo varchar(4),
curso varchar(1) not null,
turno varchar2 (5), primary key(cod_grupo),
check(curso > '0' AND curso < '4'));

create table grupo2(
  cod_grupo varchar(4) primary key,
curso varchar(1) not null,
turno varchar2 (5),
check(curso > '0' AND curso < '4'));

create table alumno(num_mat varchar(4),
nombre varchar(10) unique,
ciudad varchar(10),
cod_grupo varchar(4),
cod_grupo2 varchar(4),
primary key(num_mat),
foreign key(cod_grupo) references grupo
on delete set null,
foreign key(cod_grupo2) references grupo2
on delete set null
);

insert into grupo(cod_grupo, curso, turno) values('6666','1','tarde');
insert into grupo(cod_grupo, curso, turno) values('7777','2','sql');
insert into grupo(cod_grupo, curso, turno) values('1234','3','pizza');

insert into grupo2(cod_grupo, curso, turno) values('6666','1','tarde');
insert into grupo2(cod_grupo, curso, turno) values('7777','2','sql');
insert into grupo2(cod_grupo, curso, turno) values('1234','3','pizza');

insert into alumno(num_mat,nombre, ciudad, cod_grupo, cod_grupo2) values('145','jose luis','albacete','1234', '1234');
insert into alumno(num_mat,nombre, ciudad, cod_grupo, cod_grupo2) values('9','gepeto','albacete','7777', '7777');
insert into alumno(num_mat,nombre, ciudad, cod_grupo, cod_grupo2) values('333','patxi','bilbao','6666', '6666');

select * from grupo;
select * from alumno;

create table pertenece(
  alumno varchar2(10),
  grupo varchar(4),
  primary key(alumno,grupo),
  foreign key(alumno) references alumno,
  foreign key(grupo) references grupo
);

create table prueba(
  fecha date
);

insert into prueba values(sysdate);
insert into prueba values(TO_DATE('22/11/2018', 'dd/MM/YYYY'));

select * from prueba;

update prueba set fecha=fecha+3;

--ejercicio 1
create table persona(
  dni varchar2(9),
  nombre varchar2(10) unique,
  salario varchar(5),
  profesion varchar2(10),
  fecha_nac date,
  jubilado varchar(2) default 'no',
  primary key(dni),
  check(jubilado = 'si' OR jubilado = 'no')
);

--esto modifica la tabla
alter table persona modify nombre varchar2(10) unique;
alter table persona modify jubilado varchar(2) default 'no';

insert into persona(dni,nombre,salario,profesion,fecha_nac,jubilado) values();

select * from persona;
