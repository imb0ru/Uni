DROP DATABASE IF EXISTS dbinf23;
CREATE DATABASE IF NOT EXISTS dbinf23;
USE dbinf23;

CREATE TABLE Impiegati (
	matricola char(7) PRIMARY KEY,
	cognome varchar(30),
	nome varchar(30),
	reparto char(18)
);

CREATE TABLE Reparti(
	cod_reparto char (18),
	nome_reparto varchar (25),
	num_dipendenti integer NOT NULL,
	CONSTRAINT PRIMARY KEY (cod_reparto),
	CHECK (num_dipendenti > 0 AND num_dipendenti < 50)
);

DESCRIBE Reparti;

ALTER TABLE Impiegati 
ADD FOREIGN KEY (reparto)
	REFERENCES Reparti (cod_reparto)
	ON DELETE CASCADE
	ON UPDATE CASCADE;

INSERT INTO reparti VALUES ('hr','Personale',15);
INSERT INTO reparti VALUES ('pr','Produzione',44);

INSERT INTO impiegati
VALUES 
('111111','Rossi','Mario','hr'),
('111112','Verdi','Lucia','hr'),
('111113','Gialli','Rocco','pr'),
('111116','Gialli','Rocco','pr'),
('111114','Bianchi','Maria','pr'); 

INSERT INTO impiegati (matricola, cognome, reparto) 
VALUES ('111115','Blui','hr');

CREATE TABLE ImpiegatiPr (
	matricola char(7) PRIMARY KEY,
	cognome varchar(30),
	nome varchar(30),
	reparto char(8), 
	CONSTRAINT chiavesternareparti_FK
	FOREIGN KEY (reparto) REFERENCES Reparti (cod_reparto)
	ON DELETE CASCADE
	ON UPDATE CASCADE	
);

INSERT INTO impiegatipr
SELECT * FROM impiegati
WHERE reparto = 'pr';

-- SHOW TABLES;
-- DESCRIBE Impiegati;
-- DESCRIBE Reparti;

SELECT * FROM impiegati;

SELECT * FROM impiegati;
SELECT * FROM impiegatipr;


ALTER TABLE Impiegati 
ADD COLUMN daeliminare char(35) AFTER matricola,
ADD COLUMN eliminodipiu char(35) AFTER daeliminare;

ALTER TABLE Impiegati 
ADD COLUMN (col1 char(35), col2 char(35));

DESCRIBE Impiegati;

ALTER TABLE Impiegati 
DROP COLUMN daeliminare,
DROP COLUMN eliminodipiu,
DROP COLUMN col1,
DROP COLUMN col2
;

DESCRIBE Impiegati;

SELECT DISTINCT reparto FROM impiegati ORDER BY reparto DESC;

-- INSERT INTO reparti VALUES ('sr','Produzione', 80);

SELECT * FROM impiegati;

UPDATE impiegati
SET cognome = "Rossini"
WHERE cognome = "Rossi";
SELECT * FROM impiegati;

-- UPDATE impiegati
-- SET cognome = "Rossini", nome = "Mario";
-- SELECT * FROM impiegati;

-- DELETE FROM reparti;

UPDATE reparti
SET cod_reparto = "HumanResources"
WHERE cod_reparto = "hr";

SELECT * FROM impiegati;
SELECT * FROM impiegatipr;

SELECT cognome, nome
FROM impiegati;

SELECT cognome, nome
FROM impiegati
WHERE cognome = "Gialli";

SELECT i.cognome as Cognome, i.nome as Nome
FROM impiegati i
WHERE i.cognome = "Gialli";

SELECT nome_reparto, num_dipendenti/2 as Dipendenti_rimasti
FROM reparti;

CREATE TABLE esami(
	nome_esame char (35) PRIMARY KEY,
	cfu_esame int,
	voto_esame int,
	lode bool
);

INSERT INTO esami VALUES ('ASD', 9, 20, 0);
INSERT INTO esami VALUES ('Basi', 9, 18, 0);
INSERT INTO esami VALUES ('Fisica', 6, 26, 0);
INSERT INTO esami VALUES ('Statistica', 6, 22, 0);
INSERT INTO esami VALUES ('Discreta', 9, 18, 0);
INSERT INTO esami VALUES ('Programmazione', 12, 30, 1);
INSERT INTO esami VALUES ('Programmazione 2', 12, 28, 0);

SELECT AVG(voto_esame) as Media FROM esami;

SELECT 
	nome_esame as Esame,
	voto_esame as voto, 
	(voto_esame*cfu_esame) as voto_per_cfu,
	(voto_esame*cfu_esame)/9 as voto_standard
from esami;

SELECT sum(voto_esame * cfu_esame)/sum(cfu_esame) as votopesato 
FROM esami;

SELECT * 
FROM esami
WHERE nome_esame LIKE "%Pr%";

SELECT nome_esame as Esame
FROM esami
WHERE nome_esame like "A%";

-- ERRORE:
-- SELECT nome_esame as Esame
-- FROM esami
-- WHERE Esame like "A%";

SELECT cfu_esame as CFU, AVG(voto_esame) as Media 
FROM esami
WHERE cfu_esame <14
GROUP BY cfu_esame;

SELECT cfu_esame as CFU, AVG(voto_esame) as Media 
FROM esami
WHERE cfu_esame <14
GROUP BY CFU
HAVING Media>20;

-- ERRORE:
-- SELECT cfu_esame as CFU, AVG(voto_esame) as Media 
-- FROM esami
-- WHERE cfu_esame <14
-- HAVING Media>20;

SELECT * FROM esami;

SELECT cfu_esame as CFU, AVG(voto_esame) as Media, lode 
FROM esami
WHERE cfu_esame <14
GROUP BY CFU, lode
HAVING Media>0;

SELECT cfu_esame as CFU, AVG(voto_esame) as Media, lode 
FROM esami
WHERE cfu_esame <14
GROUP BY lode, CFU
HAVING Media>0;

SELECT * 
FROM Impiegati, Reparti
WHERE reparto = cod_reparto;

SELECT cognome, nome, nome_reparto 
FROM Impiegati, Reparti
WHERE reparto = cod_reparto;

SELECT * 
FROM Impiegati, Reparti;

SELECT cognome, nome, nome_reparto 
FROM Impiegati INNER JOIN Reparti ON reparto = cod_reparto;

SELECT cognome, nome, nome_reparto 
FROM Impiegati JOIN Reparti ON reparto = cod_reparto;

CREATE TABLE docenti_bad(
	matricola	int,
	cognome	char(35),
	nome_es char(35), 
	CONSTRAINT FOREIGN KEY (nome_es) 
	REFERENCES esami (nome_esame)
);

INSERT INTO docenti_bad VALUES(1111111, "Buono", "Basi");
INSERT INTO docenti_bad VALUES(1111111, "Di Mauro", "ASD");

SELECT * 
FROM docenti_bad NATURAL JOIN esami;


CREATE TABLE docenti (
	matricola	int,
	cognome	char(35),
	nome_esame char(35), 
	CONSTRAINT FOREIGN KEY (nome_esame) 
	REFERENCES esami (nome_esame)
);

INSERT INTO docenti VALUES(1111111, "Buono", "Basi");
INSERT INTO docenti VALUES(1111111, "Di Mauro", "ASD");

SELECT * 
FROM docenti NATURAL JOIN esami;

SELECT cognome, nome, nome_reparto 
FROM Impiegati LEFT JOIN Reparti ON reparto = cod_reparto;

SELECT cfu_esame as CFU, AVG(voto_esame) as Media, lode 
FROM esami
WHERE cfu_esame <14
GROUP BY lode, CFU
HAVING Media>0
ORDER BY Media DESC;

SELECT * 
FROM esami
ORDER BY cfu_esame, voto_esame DESC, lode;


