create database if not exists equatex;
use equatex;

create table latex_symbols
(

       symbol_id INTEGER NOT NULL PRIMARY KEY AUTO_INCREMENT,
       latex_symbol_cmd VARCHAR(50) NOT NULL
);

create table Symbols
(
       symbol_id INTEGER NOT NULL PRIMARY KEY REFERENCES latex_symbols(symbol_id),
       symbol_desc CHAR(100) NULL
);

create table Symbol_Images
(
       symbol_image_path VARCHAR(100) NOT NULL,
       symbol_image_size INTEGER NULL,
       symbol_image_width INTEGER NULL,
       symbol_image_height INTEGER NULL,
       image_type_name VARCHAR(100) NOT NULL,
       symbol_id INTEGER NOT NULL,
       PRIMARY KEY(symbol_image_path)
);



create table image_types
(
       image_type_name VARCHAR(100) NOT NULL,
       image_type_description VARCHAR(200) NULL,
       PRIMARY KEY (image_type_name)
);


      
alter table symbol_images add constraint FK_symbol_images_symbols
      FOREIGN KEY (symbol_id) references symbols(symbol_id);
      
alter table symbol_images add constraint FK_symbol_images_image_types
      FOREIGN KEY (image_type_name) references image_types(image_type_name);