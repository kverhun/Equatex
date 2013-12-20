INSERT INTO image_types(image_type_name, image_type_desc)
VALUES("default", "default symbols layout");

INSERT INTO image_types(image_type_name, image_type_desc)
VALUES("handwriting", "handwriting-like symbol layout");

insert into latex_symbols(latex_symbol_cmd)
values('1');
insert into symbols(symbol_id, symbol_desc)
values( (select symbol_id from latex_symbols
                where latex_symbol_cmd='1'),
                'digit symbol 1');

insert into latex_symbols(latex_symbol_cmd)
values('2');
insert into symbols(symbol_id, symbol_desc)
values( (select symbol_id from latex_symbols
                where latex_symbol_cmd='2'),
                'digit symbol 2');

insert into latex_symbols(latex_symbol_cmd)
values('3');
insert into symbols(symbol_id, symbol_desc)
values( (select symbol_id from latex_symbols
                where latex_symbol_cmd='3'),
                'digit symbol 3');

insert into latex_symbols(latex_symbol_cmd)
values('4');
insert into symbols(symbol_id, symbol_desc)
values( (select symbol_id from latex_symbols
                where latex_symbol_cmd='4'),
                'digit symbol 4');

insert into latex_symbols(latex_symbol_cmd)
values('5');
insert into symbols(symbol_id, symbol_desc)
values( (select symbol_id from latex_symbols
                where latex_symbol_cmd='5'),
                'digit symbol 5');

insert into latex_symbols(latex_symbol_cmd)
values('6');
insert into symbols(symbol_id, symbol_desc)
values( (select symbol_id from latex_symbols
                where latex_symbol_cmd='6'),
                'digit symbol 6');

insert into latex_symbols(latex_symbol_cmd)
values('7');
insert into symbols(symbol_id, symbol_desc)
values( (select symbol_id from latex_symbols
                where latex_symbol_cmd='7'),
                'digit symbol 7');

insert into latex_symbols(latex_symbol_cmd)
values('8');
insert into symbols(symbol_id, symbol_desc)
values( (select symbol_id from latex_symbols
                where latex_symbol_cmd='8'),
                'digit symbol 8');

insert into latex_symbols(latex_symbol_cmd)
values('9');
insert into symbols(symbol_id, symbol_desc)
values( (select symbol_id from latex_symbols
                where latex_symbol_cmd='9'),
                'digit symbol 9');

insert into latex_symbols(latex_symbol_cmd)
values('0');
insert into symbols(symbol_id, symbol_desc)
values( (select symbol_id from latex_symbols
                where latex_symbol_cmd='0'),
                'digit symbol 0');

insert into latex_symbols(latex_symbol_cmd)
values('x');
insert into symbols(symbol_id, symbol_desc)
values( (select symbol_id from latex_symbols
                where latex_symbol_cmd='x'),
                'character symbol x');

insert into latex_symbols(latex_symbol_cmd)
values('y');
insert into symbols(symbol_id, symbol_desc)
values( (select symbol_id from latex_symbols
                where latex_symbol_cmd='y'),
                'character symbol y');

insert into latex_symbols(latex_symbol_cmd)
values('z');
insert into symbols(symbol_id, symbol_desc)
values( (select symbol_id from latex_symbols
                where latex_symbol_cmd='z'),
                'character symbol z');

insert into latex_symbols(latex_symbol_cmd)
values('u');
insert into symbols(symbol_id, symbol_desc)
values( (select symbol_id from latex_symbols
                where latex_symbol_cmd='u'),
                'character symbol u');

insert into latex_symbols(latex_symbol_cmd)
values('t');
insert into symbols(symbol_id, symbol_desc)
values( (select symbol_id from latex_symbols
                where latex_symbol_cmd='t'),
                'character symbol t');

insert into latex_symbols(latex_symbol_cmd)
values('+');
insert into symbols(symbol_id, symbol_desc)
values( (select symbol_id from latex_symbols
                where latex_symbol_cmd='+'),
                'character symbol +');

insert into latex_symbols(latex_symbol_cmd)
values('-');
insert into symbols(symbol_id, symbol_desc)
values( (select symbol_id from latex_symbols
                where latex_symbol_cmd='-'),
                'character symbol -');

insert into latex_symbols(latex_symbol_cmd)
values('=');
insert into symbols(symbol_id, symbol_desc)
values( (select symbol_id from latex_symbols
                where latex_symbol_cmd='='),
                'character symbol =');

insert into latex_symbols(latex_symbol_cmd)
values('\\cdot');
insert into symbols(symbol_id, symbol_desc)
values( (select symbol_id from latex_symbols
                where latex_symbol_cmd='\\cdot'),
                'character symbol dot');

insert into latex_symbols(latex_symbol_cmd)
values('\\partial');
insert into symbols(symbol_id, symbol_desc)
values( (select symbol_id from latex_symbols
                where latex_symbol_cmd='\\partial'),
                'character symbol partial');