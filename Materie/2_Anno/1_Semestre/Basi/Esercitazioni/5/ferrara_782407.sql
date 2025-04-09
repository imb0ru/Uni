-- ESERCITAZIONE 1

DROP DATABASE IF EXISTS testateGiornalistiche_ferrara;
CREATE DATABASE IF NOT EXISTS testateGiornalistiche_ferrara;
USE testateGiornalistiche_ferrara;


-- ho impostato quasi tutti gli attributi not null per garantire consistenza in caso di omonimia, si potrebbe pensare di aggiungere un campo per il codice fiscale
CREATE TABLE redattori(
    idRedattore CHAR(3) PRIMARY KEY, -- nome dell'attributo impostato al singolare per consistenza del dato
    cognome VARCHAR(30) NOT NULL, -- dimensione impostata variabile e aumentata in caso di cognomi più lunghi (Es. Pasquadibisceglie, cognome più lungo d'Italia), impostato not null per dare dettagli in più, spesso obbligatori, rispetto al redattore
    nome VARCHAR(30) NOT NULL, -- dimensione impostata variabile e aumentata in caso di nomi di persona più lunghi (Es. Nicola Luigi Guglielmo), impostato not null per dare dettagli in più, spesso obbligatori, rispetto al redattore
    via VARCHAR(30), -- dimensione impostata variabile e aumentata in caso di nomi di vie più lunghi (es. "Tenente Cesare Suglia")
    citta VARCHAR(40) NOT NULL, -- dimensione impostata variabile e aumentata in caso di nomi di citta più lunghi (es. "San Valentino in Abruzzo Citeriore")
    provincia CHAR(2) NOT NULL,
    CAP CHAR(5) NOT NULL,
    email VARCHAR(100) NOT NULL -- dimensione impostata variabile e aumentata in caso di mail più lunghe. Impostata a NOT NULL per garantire un metodo di contatto
);

CREATE TABLE redazioni(
    idRedazione CHAR(4) PRIMARY KEY,
    nomeComitato VARCHAR(30) NOT NULL, -- dimensione impostata variabile e aumentata in caso di nomi di comitato più lunghi, impostato not null per dare dettagli in più, spesso obbligatori, rispetto al comitato
    citta VARCHAR(40) NOT NULL, -- dimensione impostata variabile e aumentata in caso di nomi di citta più lunghi (es. "San Valentino in Abruzzo Citeriore"), impostata not null per discriminare eventuali omonimi
    indirizzoWeb VARCHAR(30)
);

CREATE TABLE testate(
    idTestata CHAR(4) PRIMARY KEY,
    nome VARCHAR(20) NOT NULL, -- dimensione impostata variabile e aumentata in caso di nomi di testate più lunghi, impostato not null per dare dettagli in più, spesso obbligatori, rispetto alla testate
    redazione CHAR(4),
    FOREIGN KEY(redazione) REFERENCES redazioni(idRedazione)
    ON DELETE CASCADE
    ON UPDATE CASCADE
);

CREATE TABLE redazRedat(
    idRedazione CHAR(4),
    idRedattore CHAR(3), -- nome dell'attributo impostato al singolare per consistenza del dato
    PRIMARY KEY (idRedazione, idRedattore),
    FOREIGN KEY(idRedazione) REFERENCES redazioni(idRedazione)
    ON DELETE CASCADE
    ON UPDATE CASCADE,
    FOREIGN KEY(idRedattore) REFERENCES redattori(idRedattore)
    ON DELETE CASCADE
    ON UPDATE CASCADE
);

CREATE TABLE categorie(
    nomeCategoria VARCHAR(30) PRIMARY KEY, -- dimensione impostata variabile e aumentata in caso di nomi di categoria più lunghi
    categoriaPadre VARCHAR(30),
    FOREIGN KEY(categoriaPadre) REFERENCES categorie(nomeCategoria)
    ON DELETE CASCADE
    ON UPDATE CASCADE
);

CREATE TABLE inserzioni(
    codice CHAR(6) PRIMARY KEY,
    testo TEXT NOT NULL, -- attributo impostato text e non varchar per garantire la gestione di testi di grande dimensione
    categoria VARCHAR(30), 
    FOREIGN KEY(categoria) REFERENCES categorie(nomeCategoria)
    ON DELETE CASCADE
    ON UPDATE CASCADE 
);

CREATE TABLE instest(
    idInserzione CHAR(6),
    idTestata CHAR(4),
    PRIMARY KEY (idInserzione, idTestata),
    FOREIGN KEY(idInserzione) REFERENCES inserzioni(codice)
    ON DELETE CASCADE
    ON UPDATE CASCADE,
    FOREIGN KEY(idTestata) REFERENCES testate(idTestata)
    ON DELETE CASCADE
    ON UPDATE CASCADE
);

CREATE TABLE aziende(
    idAzienda CHAR(6) PRIMARY KEY,
    nomeAzienda VARCHAR(40) NOT NULL, -- dimensione impostata variabile, impostato not null per dare dettagli in più, spesso obbligatori, rispetto all'azienda
    referente VARCHAR(60) NOT NULL,
    telefono VARCHAR(11) NOT NULL,
    citta VARCHAR(40) NOT NULL,
    provincia CHAR(2) NOT NULL,
    CAP CHAR(5) NOT NULL,
    via VARCHAR(30) NOT NULL,
    CapitaleSociale FLOAT NOT NULL -- aggiunto attributo in correzione alla prima esercitazione
);

CREATE TABLE insaz(
    idAzienda CHAR(6),
    idInserzione CHAR(6),  -- attributo impostato a char e non a text perchè il vincolo di chiave esterna deve riferirsi alla chiave primaria, ovvero codice.
    PRIMARY KEY (idAzienda, idInserzione),
    FOREIGN KEY(idAzienda) REFERENCES aziende(idAzienda)
    ON DELETE CASCADE
    ON UPDATE CASCADE,
    FOREIGN KEY(idInserzione) REFERENCES inserzioni(codice)
    ON DELETE CASCADE
    ON UPDATE CASCADE
);

-- ho impostato tutti gli attributi not null per garantire consistenza in caso di omonimia, si potrebbe pensare di aggiungere un campo per il codice fiscale
CREATE TABLE privati(
    idPrivato CHAR(3) PRIMARY KEY, -- nome dell'attributo impostato al singolare per consistenza del dato
    cognome VARCHAR(28) NOT NULL, -- dimensione impostata variabile e aumentata in caso di cognomi più lunghi (Es. Pasquadibisceglie, cognome più lungo d'Italia), impostato not null per dare dettagli in più, spesso obbligatori, rispetto al redattore
    nome VARCHAR(28) NOT NULL, -- dimensione impostata variabile e aumentata in caso di nomi di persona più lunghi (Es. Nicola Luigi Guglielmo), impostato not null per dare dettagli in più, spesso obbligatori, rispetto al redattore
    via VARCHAR(30) NOT NULL, -- dimensione impostata variabile e aumentata in caso di nomi di vie più lunghi (es. "Tenente Cesare Suglia")
    citta VARCHAR(40) NOT NULL, -- dimensione impostata variabile e aumentata in caso di nomi di citta più lunghi (es. "San Valentino in Abruzzo Citeriore")
    provincia CHAR(2) NOT NULL,
    CAP CHAR(5) NOT NULL,
    email VARCHAR(100) NOT NULL -- dimensione impostata variabile e aumentata in caso di mail più lunghe. Impostata a NOT NULL per garantire un metodo di contatto
);

CREATE TABLE inspriv(
    idPrivato CHAR(3),  -- lunghezza impostata a 3 e non 6 come da traccia per garantire la correttezza del vincolo
    idInserzione CHAR(6),  -- attributo impostato a char e non a text perchè il vincolo di chiave esterna deve riferirsi alla chiave primaria, ovvero codice.
    PRIMARY KEY (idPrivato, idInserzione),
    FOREIGN KEY(idPrivato) REFERENCES privati(idPrivato)
    ON DELETE CASCADE
    ON UPDATE CASCADE,
    FOREIGN KEY(idInserzione) REFERENCES inserzioni(codice)
    ON DELETE CASCADE
    ON UPDATE CASCADE
);


-- ESERCITAZIONE 2

-- 1 almeno tre testate di giornale
INSERT INTO testate(idTestata, nome) VALUES ("T001", "Corriere della Sera"); 
INSERT INTO testate(idTestata, nome) VALUES ("T002", "La Repubblica"); 
INSERT INTO testate(idTestata, nome) VALUES ("T003", "Il Sole 24 Ore");

DESCRIBE privati;

ALTER TABLE privati
MODIFY cognome VARCHAR(30); 

ALTER TABLE privati
MODIFY nome VARCHAR(30); 

DESCRIBE privati;

CREATE TABLE citta(
    CAP CHAR(5) PRIMARY KEY,
    citta VARCHAR(40) NOT NULL, -- dimensione impostata variabile e aumentata in caso di nomi di citta più lunghi (es. "San Valentino in Abruzzo Citeriore")
    provincia CHAR(2) NOT NULL
);

DESCRIBE redattori;

ALTER TABLE redattori
DROP COLUMN citta,
DROP COLUMN provincia,
MODIFY CAP char(5),
ADD CONSTRAINT FOREIGN KEY(CAP) 
REFERENCES citta(CAP) 
ON DELETE CASCADE 
ON UPDATE CASCADE;

DESCRIBE redattori;

DESCRIBE aziende;

ALTER TABLE aziende
DROP COLUMN citta,
DROP COLUMN provincia,
MODIFY CAP char(5),
ADD CONSTRAINT FOREIGN KEY(CAP) 
REFERENCES citta(CAP) 
ON DELETE CASCADE 
ON UPDATE CASCADE;

DESCRIBE aziende;

DESCRIBE privati;

ALTER TABLE privati
DROP COLUMN citta,
DROP COLUMN provincia,
MODIFY CAP char(5),
ADD CONSTRAINT FOREIGN KEY(CAP) 
REFERENCES citta(CAP) 
ON DELETE CASCADE 
ON UPDATE CASCADE;

DESCRIBE privati;

DESCRIBE redazioni;

ALTER TABLE redazioni
MODIFY citta char(5),
ADD CONSTRAINT FOREIGN KEY(citta) 
REFERENCES citta(CAP) 
ON DELETE CASCADE 
ON UPDATE CASCADE;

DESCRIBE redazioni;

-- 2 tanti comitati di redazioni quante sono le testate di giornale inserite
INSERT INTO redazioni(idRedazione, nomeComitato, indirizzoWeb) VALUES ("R001","Ferrara - Ardito", "www.fer.ard.it");
INSERT INTO redazioni(idRedazione, nomeComitato, indirizzoWeb) VALUES ("R002", "Carbonara - Appice", "www.carb.app.it");
INSERT INTO redazioni(idRedazione, nomeComitato, indirizzoWeb) VALUES ("R003", "De Giglio - Di Chio", NULL);

SELECT * FROM redazioni;

-- 3 un numero di persone superiore o uguale a tre, che compongono i comitati di redazione, tenendo conto che qualche redattore può far parte di più comitati
INSERT INTO redattori(idRedattore, cognome, nome, email) VALUES ("R01", "Ferrara", "Marco", "m.ferrara62@studenti.uniba.it");
INSERT INTO redattori(idRedattore, cognome, nome, email) VALUES ("R02", "Ardito", "Luca", "l.ardito12@studenti.uniba.it");
INSERT INTO redattori(idRedattore, cognome, nome, email) VALUES ("R03", "Carbonara", "Achille", "a.carbonara@studenti.uniba.it");
INSERT INTO redattori(idRedattore, cognome, nome, email) VALUES ("R04", "Appice", "Lorenzo", "l.appice@studenti.uniba.it");
INSERT INTO redattori(idRedattore, cognome, nome, email) VALUES ("R05", "De Giglio", "Pietro", "p.degiglio@studenti.uniba.it");
INSERT INTO redattori(idRedattore, cognome, nome, email) VALUES ("R06", "Di Chio", "Maria Teresa", "m.dichio9@studenti.uniba.it");

SELECT * FROM redattori;

UPDATE testate
SET redazione = "R001" 
WHERE idTestata = "T001";

UPDATE testate
SET redazione = "R002" 
WHERE idTestata = "T002";

UPDATE testate
SET redazione = "R003" 
WHERE idTestata = "T003";

INSERT INTO redazRedat (idRedazione, idRedattore) VALUES ("R001", "R01");
INSERT INTO redazRedat (idRedazione, idRedattore) VALUES ("R001", "R02");
INSERT INTO redazRedat (idRedazione, idRedattore) VALUES ("R002", "R03");
INSERT INTO redazRedat (idRedazione, idRedattore) VALUES ("R002", "R04");
INSERT INTO redazRedat (idRedazione, idRedattore) VALUES ("R003", "R05");
INSERT INTO redazRedat (idRedazione, idRedattore) VALUES ("R003", "R06");

-- -SHOW CREATE TABLE categorie;

ALTER TABLE categorie DROP CONSTRAINT categorie_ibfk_1;
ALTER TABLE categorie DROP KEY categoriaPadre;

-- -SHOW CREATE TABLE inserzioni;

ALTER TABLE inserzioni DROP CONSTRAINT inserzioni_ibfk_1;
ALTER TABLE inserzioni DROP KEY categoria;

ALTER TABLE categorie DROP PRIMARY KEY;
ALTER TABLE categorie ADD COLUMN idCategoria char(4) PRIMARY KEY;
ALTER TABLE categorie MODIFY COLUMN categoriaPadre char(4);
ALTER TABLE inserzioni MODIFY COLUMN categoria char(4);

ALTER TABLE categorie
ADD FOREIGN KEY (categoriaPadre)
REFERENCES categorie(idCategoria)
ON DELETE CASCADE
ON UPDATE CASCADE;

DESCRIBE categorie;

ALTER TABLE inserzioni
ADD FOREIGN KEY (categoria)
REFERENCES categorie(idCategoria)
ON DELETE CASCADE
ON UPDATE CASCADE;

DESCRIBE inserzioni;

-- 4 le categorie degli articoli, e ognuna con un diverso numero di sottocategorie (es. affitti e vendite sono sottocategorie di case)
INSERT INTO categorie (idCategoria, nomeCategoria, categoriaPadre) VALUES ("C001", "Cronaca", NULL);
INSERT INTO categorie (idCategoria, nomeCategoria, categoriaPadre) VALUES ("C002", "Nera", "C001");
INSERT INTO categorie (idCategoria, nomeCategoria, categoriaPadre) VALUES ("C003", "Rosa", "C001");
INSERT INTO categorie (idCategoria, nomeCategoria, categoriaPadre) VALUES ("C004", "Sport", NULL);
INSERT INTO categorie (idCategoria, nomeCategoria, categoriaPadre) VALUES ("C005", "Calcio", "C004");
INSERT INTO categorie (idCategoria, nomeCategoria, categoriaPadre) VALUES ("C006", "Pallacanestro", "C004");
INSERT INTO categorie (idCategoria, nomeCategoria, categoriaPadre) VALUES ("C007", "Consulenza", NULL);
INSERT INTO categorie (idCategoria, nomeCategoria, categoriaPadre) VALUES ("C008", "Formazione", "C007");
INSERT INTO categorie (idCategoria, nomeCategoria, categoriaPadre) VALUES ("C009", "Economia", "C007");
INSERT INTO categorie (idCategoria, nomeCategoria, categoriaPadre) VALUES ("C010", "Finanza", "C009");
INSERT INTO categorie (idCategoria, nomeCategoria, categoriaPadre) VALUES ("C011", "Tecnologia", NULL);
INSERT INTO categorie (idCategoria, nomeCategoria, categoriaPadre) VALUES ("C012", "Informatica", "C011");
INSERT INTO categorie (idCategoria, nomeCategoria, categoriaPadre) VALUES ("C013", "Hobby", NULL);
INSERT INTO categorie (idCategoria, nomeCategoria, categoriaPadre) VALUES ("C014", "Cucina", "C013");
INSERT INTO categorie (idCategoria, nomeCategoria, categoriaPadre) VALUES ("C015", "Arte", "C013");
INSERT INTO categorie (idCategoria, nomeCategoria, categoriaPadre) VALUES ("C016", "Musica", "C013");
INSERT INTO categorie (idCategoria, nomeCategoria, categoriaPadre) VALUES ("C017", "Vendita Usato", NULL);

SELECT * FROM categorie;

INSERT INTO citta(CAP, citta, provincia) VALUES("20121", "Milano", "MI");
INSERT INTO citta(CAP, citta, provincia) VALUES ("20122", "Milano", "MI");
INSERT INTO citta(CAP, citta, provincia) VALUES ("00100", "Roma", "RM");
INSERT INTO citta(CAP, citta, provincia) VALUES ("00121", "Roma", "RM");
INSERT INTO citta(CAP, citta, provincia) VALUES ("80121", "Napoli", "NA");
INSERT INTO citta(CAP, citta, provincia) VALUES ("80132", "Napoli", "NA");
INSERT INTO citta(CAP, citta, provincia) VALUES ("10100", "Torino", "TO");
INSERT INTO citta(CAP, citta, provincia) VALUES ("10132", "Torino", "TO");
INSERT INTO citta(CAP, citta, provincia) VALUES ("50100", "Firenze", "FI");
INSERT INTO citta(CAP, citta, provincia) VALUES ("50132", "Firenze", "FI");
INSERT INTO citta(CAP, citta, provincia) VALUES ("70121", "Bari", "BA");
INSERT INTO citta(CAP, citta, provincia) VALUES ("70126", "Bari", "BA");

SELECT * FROM citta;

UPDATE redattori
SET CAP = "70126";

UPDATE redazioni
SET citta = "70126";

-- 5 almeno 10 inserzioni di privati e 10 inserzioni di aziende;
INSERT INTO aziende (idAzienda, nomeAzienda, referente, telefono, CAP, via, CapitaleSociale) VALUES ("AZ0001", "La Stampa S.p.A.", "Mario Rossi", "0111234567", "70126", "Via Garibaldi", 100000.00);
INSERT INTO aziende (idAzienda, nomeAzienda, referente, telefono, CAP, via, CapitaleSociale) VALUES ("AZ0002", "Il Giornale Editore", "Luigi Verdi", "0287654321", "20121","Via Dante", 120000.00);
INSERT INTO aziende (idAzienda, nomeAzienda, referente, telefono, CAP, via, CapitaleSociale) VALUES ("AZ0003", "Roma News Media", "Anna Bianchi", "0678901234", "00100", "Via Roma", 80000.00);
INSERT INTO aziende (idAzienda, nomeAzienda, referente, telefono, CAP, via, CapitaleSociale) VALUES ("AZ0004", "Napoli Informa", "Giovanni Russo", "0813456789", "80121", "Via Napoli", 90000.00);
INSERT INTO aziende (idAzienda, nomeAzienda, referente, telefono, CAP, via, CapitaleSociale) VALUES ("AZ0005", "Torino Press", "Elena Ferrari", "0119876543", "10100", "Via Torino", 110000.00);
INSERT INTO aziende (idAzienda, nomeAzienda, referente, telefono, CAP, via, CapitaleSociale) VALUES ("AZ0006", "Firenze Notizie", "Alessio Rossi", "0552345678", "50100", "Via Firenze", 95000.00);
INSERT INTO aziende (idAzienda, nomeAzienda, referente, telefono, CAP, via, CapitaleSociale) VALUES ("AZ0007", "Bari Today", "Giulia Esposito", "0808765432", "70121", "Via Bari", 85000.00);
INSERT INTO aziende (idAzienda, nomeAzienda, referente, telefono, CAP, via, CapitaleSociale) VALUES ("AZ0008", "Milano Chronicle", "Roberto Colombo", "0287654321", "20122", "Via Milano", 120000.00);
INSERT INTO aziende (idAzienda, nomeAzienda, referente, telefono, CAP, via, CapitaleSociale) VALUES ("AZ0009", "Il Messaggero Editore", "Maria Esposito", "0678901234", "00121", "Via Napoli", 90000.00);
INSERT INTO aziende (idAzienda, nomeAzienda, referente, telefono, CAP, via, CapitaleSociale) VALUES ("AZ0010", "Napoli Daily", "Antonio Ricci", "0813456789", "80132", "Via Roma", 100000.00);

SELECT * FROM aziende;

INSERT INTO privati (idPrivato, cognome, nome, via, CAP, email) VALUES ("P01", "Rossi", "Mario", "Via Garibaldi", "70126", "m.rossi@email.com");
INSERT INTO privati (idPrivato, cognome, nome, via, CAP, email) VALUES ("P02", "Verdi", "Luigi", "Via Dante", "20121", "l.verdi@email.com");
INSERT INTO privati (idPrivato, cognome, nome, via, CAP, email) VALUES ("P03", "Bianchi", "Anna", "Via Roma", "00100", "a.bianchi@email.com");
INSERT INTO privati (idPrivato, cognome, nome, via, CAP, email) VALUES ("P04", "Russo", "Giovanni", "Via Napoli", "80121", "g.russo@email.com");
INSERT INTO privati (idPrivato, cognome, nome, via, CAP, email) VALUES ("P05", "Ferrari", "Elena", "Via Torino", "10100", "e.ferrari@email.com");
INSERT INTO privati (idPrivato, cognome, nome, via, CAP, email) VALUES ("P06", "Esposito", "Laura", "Via Firenze", "50100", "l.esposito@email.com");
INSERT INTO privati (idPrivato, cognome, nome, via, CAP, email) VALUES ("P07", "Colombo", "Roberto", "Via Bari", "20122", "r.colombo@email.com");
INSERT INTO privati (idPrivato, cognome, nome, via, CAP, email) VALUES ("P08", "Azzurri", "Maria", "Via Milano", "00121", "m.esposito@email.com");
INSERT INTO privati (idPrivato, cognome, nome, via, CAP, email) VALUES ("P09", "Ricci", "Antonio", "Via Napoli", "80132", "a.ricci@email.com");
INSERT INTO privati (idPrivato, cognome, nome, via, CAP, email) VALUES ("P10", "Porpora", "Giovanna", "Via Roma", "70121", "g.bianchi@email.com");

SELECT * FROM privati;

INSERT INTO inserzioni (codice, testo, categoria) VALUES ("P00001", "Vendo libri usati, ottimo stato", "C017");
INSERT INTO inserzioni (codice, testo, categoria) VALUES ("P00002", "Lezioni di yoga e meditazione a domicilio", "C013");
INSERT INTO inserzioni (codice, testo, categoria) VALUES ("P00003", "Consulenza legale per questioni familiari", "C007");
INSERT INTO inserzioni (codice, testo, categoria) VALUES ("P00004", "Ripetizioni di chimica per studenti universitari", "C008");
INSERT INTO inserzioni (codice, testo, categoria) VALUES ("P00005", "Assistenza informatica e risoluzione problemi", "C012");
INSERT INTO inserzioni (codice, testo, categoria) VALUES ("P00006", "Consulenza finanziaria per investimenti a breve termine", "C010");
INSERT INTO inserzioni (codice, testo, categoria) VALUES ("P00007", "Corso di fotografia avanzato", "C013");
INSERT INTO inserzioni (codice, testo, categoria) VALUES ("P00008", "Riparazione elettrodomestici, preventivi gratuiti", "C011");
INSERT INTO inserzioni (codice, testo, categoria) VALUES ("P00009", "Lezioni di pianoforte per principianti", "C016");
INSERT INTO inserzioni (codice, testo, categoria) VALUES ("P00010", "Vendo mobili antichi, collezione personale", "C017");

SELECT * FROM inserzioni;

INSERT INTO inspriv (idPrivato, idInserzione) VALUES ("P01", "P00001");
INSERT INTO inspriv (idPrivato, idInserzione) VALUES ("P02", "P00002");
INSERT INTO inspriv (idPrivato, idInserzione) VALUES ("P03", "P00003");
INSERT INTO inspriv (idPrivato, idInserzione) VALUES ("P04", "P00004");
INSERT INTO inspriv (idPrivato, idInserzione) VALUES ("P05", "P00005");
INSERT INTO inspriv (idPrivato, idInserzione) VALUES ("P06", "P00006");
INSERT INTO inspriv (idPrivato, idInserzione) VALUES ("P07", "P00007");
INSERT INTO inspriv (idPrivato, idInserzione) VALUES ("P08", "P00008");
INSERT INTO inspriv (idPrivato, idInserzione) VALUES ("P09", "P00009");
INSERT INTO inspriv (idPrivato, idInserzione) VALUES ("P10", "P00010");

SELECT * FROM inspriv;

INSERT INTO inserzioni (codice, testo, categoria) VALUES ("A00001", "Offerte speciali su abbonamenti alla rubrica sportiva", "C004");
INSERT INTO inserzioni (codice, testo, categoria) VALUES ("A00002", "Nuova collezione di libri d'arte", "C013");
INSERT INTO inserzioni (codice, testo, categoria) VALUES ("A00003", "Abbonamenti digitali convenienti per le news di cronaca", "C001");
INSERT INTO inserzioni (codice, testo, categoria) VALUES ("A00004", "Anteprima su eventi culturali a Napoli", "C003");
INSERT INTO inserzioni (codice, testo, categoria) VALUES ("A00005", "Sconti sugli abbonamenti alla rubrica calcistica", "C005");
INSERT INTO inserzioni (codice, testo, categoria) VALUES ("A00006", "Offerte vantaggiose su abbonamenti a news di cronaca", "C003");
INSERT INTO inserzioni (codice, testo, categoria) VALUES ("A00007", "Offerte esclusive per abbonamenti alle notizie locali", "C003");
INSERT INTO inserzioni (codice, testo, categoria) VALUES ("A00008", "Accesso premium a notizie di cronaca su Milano", "C003");
INSERT INTO inserzioni (codice, testo, categoria) VALUES ("A00009", "Sconti sugli abbonamenti alla rubrica finanziaria", "C010");
INSERT INTO inserzioni (codice, testo, categoria) VALUES ("A00010", "Anteprima su eventi a Bari", "C003");

SELECT * FROM inserzioni;

INSERT INTO insaz (idAzienda, idInserzione) VALUES ("AZ0001", "A00001");
INSERT INTO insaz (idAzienda, idInserzione) VALUES ("AZ0002", "A00002");
INSERT INTO insaz (idAzienda, idInserzione) VALUES ("AZ0003", "A00003");
INSERT INTO insaz (idAzienda, idInserzione) VALUES ("AZ0004", "A00004");
INSERT INTO insaz (idAzienda, idInserzione) VALUES ("AZ0005", "A00005");
INSERT INTO insaz (idAzienda, idInserzione) VALUES ("AZ0006", "A00006");
INSERT INTO insaz (idAzienda, idInserzione) VALUES ("AZ0007", "A00007");
INSERT INTO insaz (idAzienda, idInserzione) VALUES ("AZ0008", "A00008");
INSERT INTO insaz (idAzienda, idInserzione) VALUES ("AZ0009", "A00009");
INSERT INTO insaz (idAzienda, idInserzione) VALUES ("AZ0010", "A00010");

SELECT * FROM insaz;

INSERT INTO instest (idInserzione, idTestata) VALUES ("A00001", "T001"); 
INSERT INTO instest (idInserzione, idTestata) VALUES ("A00002", "T001"); 
INSERT INTO instest (idInserzione, idTestata) VALUES ("A00003", "T001"); 
INSERT INTO instest (idInserzione, idTestata) VALUES ("A00004", "T002"); 
INSERT INTO instest (idInserzione, idTestata) VALUES ("A00005", "T002"); 
INSERT INTO instest (idInserzione, idTestata) VALUES ("A00006", "T002"); 
INSERT INTO instest (idInserzione, idTestata) VALUES ("A00007", "T002"); 
INSERT INTO instest (idInserzione, idTestata) VALUES ("A00008", "T003"); 
INSERT INTO instest (idInserzione, idTestata) VALUES ("A00009", "T003"); 
INSERT INTO instest (idInserzione, idTestata) VALUES ("A00010", "T003"); 
INSERT INTO instest (idInserzione, idTestata) VALUES ("P00001", "T001"); 
INSERT INTO instest (idInserzione, idTestata) VALUES ("P00002", "T001"); 
INSERT INTO instest (idInserzione, idTestata) VALUES ("P00003", "T001"); 
INSERT INTO instest (idInserzione, idTestata) VALUES ("P00004", "T002"); 
INSERT INTO instest (idInserzione, idTestata) VALUES ("P00005", "T002"); 
INSERT INTO instest (idInserzione, idTestata) VALUES ("P00006", "T002"); 
INSERT INTO instest (idInserzione, idTestata) VALUES ("P00007", "T002"); 
INSERT INTO instest (idInserzione, idTestata) VALUES ("P00008", "T003"); 
INSERT INTO instest (idInserzione, idTestata) VALUES ("P00009", "T003"); 
INSERT INTO instest (idInserzione, idTestata) VALUES ("P00010", "T003"); 

-- -SHOW CREATE TABLE inspriv;

/* non posso creare un vincolo di reazione alla tabella inspriv
   in modo che se il codice di inserzioni viene modificato/cancellato, 
   nella tabella inspriv idInserzione sia settato a NULL poichè,
   oltre che chiave esterna, idInserzione è anche chiave primaria.
   Di conseguenza non potrà avere valore nullo.
*/

-- 6 visualizzare il nome di tutte le testate presenti nel database
SELECT nome AS Testata 
FROM testate;

-- 7 visualizzare l'elenco dei redattori presenti nel database, mostrando tutte le informazioni disponibili
SELECT * 
FROM redattori;

-- 8 visualizzare l'elenco dei redattori presenti nel database, mostrando cognome e nome
SELECT cognome AS CognomeRedattore, nome AS NomeRedattore 
FROM redattori;

-- 9 visualizzare l'elenco dei redattori presenti nel database, mostrando cognome, nome ed e-mail
SELECT cognome AS CognomeRedattore, nome AS NomeRedattore, eMail AS email 
FROM redattori;

-- 10 visualizzare l'elenco dei redattori presenti nel database la cui e-mail inizia con la lettera a
SELECT * 
FROM redattori 
WHERE email LIKE "a%";

-- 11 visualizzare i redattori che hanno inserito un'email corretta (quelli in cui il campo e-mail contiene una chiocciola
SELECT * 
FROM redattori 
WHERE email LIKE "%@%";

-- 12 visualizzare i redattori che hanno inserito un'email sbagliata (quelli in cui il campo e-mail NON contiene una chiocciola
SELECT * 
FROM redattori 
WHERE email NOT LIKE "%@%";

-- 13 visualizzare il nome di comitato di tutte le redazioni presenti nel database, se presente anche l'indirizzo web
SELECT nomeComitato, indirizzoWeb 
FROM redazioni;

-- 14 visualizzare il testo e il codice delle inserzioni della categoria 'casa', se questa categoria non è presente prenderne un'altra
SELECT testo, codice
FROM inserzioni 
WHERE categoria = "C012";

-- 15 visualizzare il codice e il testo di tutte le inserzioni che hanno al loro interno la parola 'casa'
SELECT codice, testo 
FROM inserzioni 
WHERE testo LIKE "%casa%";

-- 16 visualizzare il codice e il testo di tutte le inserzioni che hanno al loro interno la parola 'casa' e la sottostringa 'vend'
SELECT codice, testo 
FROM inserzioni 
WHERE testo LIKE "%casa%" 
AND testo LIKE "%vend%";

-- 17 visualizzare il codice e il testo di tutte le inserzioni che hanno al loro interno la sottostringa 'modic'
SELECT codice, testo 
FROM inserzioni 
WHERE testo LIKE "%modic%";

-- 18 visualizzare l'elenco dei privati presenti nel database
SELECT * 
FROM privati;

-- 19 visualizzare l'elenco dei privati provenienti dalla città con CAP: 70125 o 70126
SELECT * 
FROM privati 
WHERE CAP IN ('70125', '70126');

-- 20 visualizzare l'elenco delle aziende il cui telefono contiene le cifre: 556
SELECT * 
FROM aziende 
WHERE telefono LIKE "%556%";


-- ESERCITAZIONE 3

SELECT * 
FROM testate;

SELECT * 
FROM redazioni;

SELECT * 
FROM redattori;

SELECT * 
FROM categorie;

SELECT * 
FROM inserzioni;

ALTER TABLE privati
ADD COLUMN eta INT;
ALTER TABLE privati
ADD COLUMN numeroCivico INT AFTER via;

ALTER TABLE aziende
ADD COLUMN numeroCivico INT;
ALTER TABLE aziende
ADD COLUMN annoFondazione INT(4);

DESCRIBE privati;
DESCRIBE aziende;

-- genero casualmente i numeri civici e le eta per popolare rapidamente le righe delle tabelle
UPDATE privati
SET numeroCivico = FLOOR(RAND() * 100) + 1;

UPDATE privati
SET eta = FLOOR(RAND() * 100) + 1;

SELECT * 
FROM privati;

UPDATE aziende
SET annoFondazione = FLOOR(RAND() * (2023 - 1800 + 1)) + 1800;

UPDATE aziende
SET numeroCivico = FLOOR(RAND() * 100) + 1;

SELECT * 
FROM aziende;

-- 21 visualizzare il nome di tutte le aziende presenti nel database;
SELECT nomeAzienda AS Azienda 
FROM aziende;

-- 22 visualizzare il nome di tutte le aziende presenti nel database aventi anno di fondazione precedente al 1980
SELECT nomeAzienda AS Azienda 
FROM aziende 
WHERE annoFondazione < 1980;

-- 23 visualizzare il nome di tutte le aziende presenti nel database aventi anno di fondazione successivo al 1998
SELECT nomeAzienda AS Azienda 
FROM aziende 
WHERE annoFondazione > 1998;

-- 24 visualizzare il nome di tutte le aziende presenti nel database aventi anno di fondazione compreso tra il 1980 e il 1998
SELECT nomeAzienda AS Azienda 
FROM aziende 
WHERE annoFondazione BETWEEN 1980 AND 1998;

-- 25 visualizzare l'elenco dei privati presenti nel database, mostrando tutte le informazioni disponibili, evitando l'uso dell'asterisco
SELECT idPrivato, cognome, nome, via, CAP, email 
FROM privati;

-- 26 visualizzare l'elenco dei privati presenti nel database che abitano in un numero civico superiore a 20, mostrando cognome e nome e numero civico
SELECT cognome, nome, numeroCivico 
FROM privati 
WHERE numeroCivico > 20;

-- 27 visualizzare l'elenco dei privati presenti nel database che abitano in un numero civico pari a 10 o a 15, mostrando cognome e nome e numero civico
SELECT cognome, nome, numeroCivico 
FROM privati 
WHERE numeroCivico IN (10, 15);

-- 28 visualizzare nome, cognome, via, numero civico e CAP dei privati il cui numero civico è compreso tra 15 e 30, visualizzare CAP come Codice_Avviamento_Postale
SELECT nome, cognome, via, numeroCivico, CAP AS Codice_Avviamento_Postale 
FROM privati 
WHERE numeroCivico BETWEEN 15 AND 30;

-- 29 visualizzare il nome e il capitale sociale delle aziende, visualizzare anche la metà del capitale sociale con il nome: Plafond_max_disponibile
SELECT nomeAzienda AS Azienda, capitaleSociale AS Capitale_Sociale, (capitaleSociale/2) AS Plafond_max_disponibile 
FROM aziende;

-- 30 visualizzare le età e il nome dei privati che hanno un'età inferiore a 30
SELECT eta, nome 
FROM privati 
WHERE eta < 30;

-- 31 visualizzare il nome di comitato di tutte le redazioni presenti nel database che hanno all'interno del nome una sottostringa costituita da tre lettere di cui ma lettera centrale non è importante: "m t"
SELECT nomeComitato 
FROM redazioni 
WHERE nomeComitato LIKE "%m_t%";

-- 32 creare una tabella PrivatiGiovani con le stesse caratteristiche della tabella Privati e senza vincoli di integrità interrelazionali
CREATE TABLE privatiGiovani AS SELECT * FROM privati WHERE false;

-- 33 inserire nella tabella PrivatiGiovani tutti i privati contenuti nella tabella Privati che hanno età inferiore a 30
INSERT INTO privatiGiovani SELECT * FROM privati WHERE eta < 30;

DESCRIBE privatiGiovani;
SELECT * 
FROM privatiGiovani;

-- 34 Rinominare il cognome dei PrivatiGiovani il cui cognome inizia con la lettera "P" con la parola "Rossi"
UPDATE privatiGiovani
SET cognome = "Rossi"
WHERE cognome LIKE "P%";

-- 35 Rinominare il nome dei PrivatiGiovani il cui nome contiene la sottostringa "aur" con la parola "Arnold"
UPDATE privatiGiovani
SET nome = "Arnold"
WHERE nome LIKE "%aur%";

SELECT * 
FROM privatiGiovani;

-- 36 visualizzare cognome, nome ed età dei privati il cui nome è Arnold, in particolare visualizzare il campo nome come "Nick"
SELECT cognome, nome AS Nick, eta 
FROM privati 
WHERE nome = "Arnold";

-- 37 visualizzare cognome, nome ed età dei privati il cui cognome è "Rossi", in particolare visualizzare un unico campo cognomenome come "Pilota"
SELECT CONCAT(cognome, " ", nome) AS Pilota, eta 
FROM privati 
WHERE cognome = "Rossi";

-- 38 visualizzare l'elenco delle aziende il cui telefono inizia per 080.
SELECT * 
FROM aziende 
WHERE telefono LIKE "080%";


-- ESERCITAZIONE 4

-- 39 visualizzare il nome e il numero civico di tutte le aziende presenti nel database che hanno o potrebbero avere un numero civico superiore a 15
SELECT nomeAzienda, numeroCivico
FROM aziende 
WHERE numeroCivico > 15 
OR numeroCivico IS NULL;

-- 40 visualizzare il nome e l'anno di fondazione di tutte le aziende presenti nel database che hanno o potrebbero avere anno di fondazione precedente al 1980
SELECT nomeAzienda, annoFondazione 
FROM aziende 
WHERE annoFondazione < 1980 
OR numeroCivico IS NULL;

-- 41 visualizzare il nome di tutte le aziende presenti nel database che hanno o potrebbero avere anno di fondazione compreso tra il 1980 e il 1998
SELECT nomeAzienda 
FROM aziende 
WHERE annoFondazione BETWEEN 1980 AND 1998 
OR annoFondazione IS NULL;

-- 42 visualizzare codice, testo e categoria delle inserzioni presenti nel database
SELECT codice, testo, categoria 
FROM inserzioni;

-- 43 visualizzare l'elenco dei codici di inserzioni e dei codici delle aziende (tabella insaz)
SELECT * 
FROM insaz;

-- 44 visualizzare per ogni codice articolo presente in insaz nome azienda, referente e telefono utilizzando il prodotto cartesiano
SELECT idInserzione, nomeAzienda, referente, telefono 
FROM insaz, aziende;

-- 45 mostra, utilizzando il prodotto cartesiano, codice, testo e categoria delle inserzioni con relativi nome azienda, referente, telefono, utilizzando le tabelle aziende, insaz e inserzioni
SELECT codice, testo, categoria, nomeAzienda, referente, telefono 
FROM inserzioni, insaz, aziende;

-- 46 visualizzare l'interrogazione precedente effettuando le seguenti ridenominazioni sulle relative tabelle: aziende in elenco_aziende, insaz in IA, inserzioni in pubblicazioni
SELECT pubblicazioni.codice, pubblicazioni.testo, pubblicazioni.categoria, elenco_aziende.nomeAzienda, elenco_aziende.referente, elenco_aziende.telefono 
FROM inserzioni AS pubblicazioni, insaz AS IA, aziende AS elenco_aziende;

-- 47 visualizzare l'interrogazione precedente ridenominando i seguenti attributi: codice in codice_articolo, testo in descrizione
SELECT pubblicazioni.codice AS codice_articolo, pubblicazioni.testo AS descrizione, pubblicazioni.categoria, elenco_aziende.nomeAzienda, elenco_aziende.referente, elenco_aziende.telefono 
FROM inserzioni AS pubblicazioni, insaz AS IA, aziende AS elenco_aziende;

-- 48 della query precedente visualizzare solo le aziende che hanno un capitale sociale superiore 18000000;
SELECT pubblicazioni.codice AS codice_articolo, pubblicazioni.testo AS descrizione, pubblicazioni.categoria, elenco_aziende.nomeAzienda, elenco_aziende.referente, elenco_aziende.telefono 
FROM inserzioni AS pubblicazioni, insaz AS IA, aziende AS elenco_aziende
WHERE elenco_aziende.capitaleSociale > 18000000;

-- 49 visualizzare l'elenco dei nomi dei privati presenti nel database;
SELECT nome 
FROM privati;

-- 50 visualizzare l'elenco dei nomi dei privati diversi presenti nel database;
SELECT DISTINCT nome 
FROM privati;

-- 51 ripetere le interrogazioni dalla numero 45 alla numero 48 utilizzando il NATURAL JOIN (Join naturale);
SELECT codice, testo, categoria, nomeAzienda, referente, telefono 
FROM inserzioni 
NATURAL JOIN insaz 
NATURAL JOIN aziende
WHERE insaz.idInserzione = inserzioni.codice;

SELECT pubblicazioni.codice, pubblicazioni.testo, pubblicazioni.categoria, elenco_aziende.nomeAzienda, elenco_aziende.referente, elenco_aziende.telefono 
FROM inserzioni AS pubblicazioni NATURAL JOIN insaz AS IA 
NATURAL JOIN aziende AS elenco_aziende
WHERE IA.idInserzione = pubblicazioni.codice;

SELECT pubblicazioni.codice AS codice_articolo, pubblicazioni.testo AS descrizione, pubblicazioni.categoria, elenco_aziende.nomeAzienda, elenco_aziende.referente, elenco_aziende.telefono 
FROM inserzioni AS pubblicazioni 
NATURAL JOIN insaz AS IA 
NATURAL JOIN aziende AS elenco_aziende
WHERE IA.idInserzione = pubblicazioni.codice;

SELECT pubblicazioni.codice AS codice_articolo, pubblicazioni.testo AS descrizione, pubblicazioni.categoria, elenco_aziende.nomeAzienda, elenco_aziende.referente, elenco_aziende.telefono 
FROM inserzioni AS pubblicazioni 
NATURAL JOIN insaz AS IA 
NATURAL JOIN aziende AS elenco_aziende
WHERE IA.idInserzione = pubblicazioni.codice
AND elenco_aziende.capitaleSociale > 18000000;

-- 52 ripetere le interrogazioni dalla numero 45 alla numero 48 utilizzando il Theta JOIN (Join esplicito)
SELECT codice, testo, categoria, nomeAzienda, referente, telefono 
FROM inserzioni JOIN insaz ON  insaz.idInserzione = inserzioni.codice
JOIN aziende ON insaz.idAzienda = aziende.idAzienda;

SELECT pubblicazioni.codice, pubblicazioni.testo, pubblicazioni.categoria, elenco_aziende.nomeAzienda, elenco_aziende.referente, elenco_aziende.telefono 
FROM inserzioni AS pubblicazioni JOIN insaz AS IA ON IA.idInserzione = pubblicazioni.codice
JOIN aziende AS elenco_aziende ON IA.idAzienda = elenco_aziende.idAzienda;

SELECT pubblicazioni.codice AS codice_articolo, pubblicazioni.testo AS descrizione, pubblicazioni.categoria, elenco_aziende.nomeAzienda, elenco_aziende.referente, elenco_aziende.telefono 
FROM inserzioni AS pubblicazioni JOIN insaz AS IA ON IA.idInserzione = pubblicazioni.codice
JOIN aziende AS elenco_aziende ON IA.idAzienda = elenco_aziende.idAzienda;

SELECT pubblicazioni.codice AS codice_articolo, pubblicazioni.testo AS descrizione, pubblicazioni.categoria, elenco_aziende.nomeAzienda, elenco_aziende.referente, elenco_aziende.telefono 
FROM inserzioni AS pubblicazioni JOIN insaz AS IA ON IA.idInserzione = pubblicazioni.codice
JOIN aziende AS elenco_aziende ON IA.idAzienda = elenco_aziende.idAzienda
WHERE elenco_aziende.capitaleSociale > 18000000;

-- 53 visualizzare l'interrogazione al punto 45 ordinata per numeri di telefono;
SELECT codice, testo, categoria, nomeAzienda, referente, telefono 
FROM inserzioni, insaz, aziende 
ORDER BY telefono;

-- 54 visualizzare l'interrogazione al punto 45 ordinata per numeri di telefono decrescenti
SELECT codice, testo, categoria, nomeAzienda, referente, telefono 
FROM inserzioni, insaz, aziende
ORDER BY telefono DESC;

-- 55 visualizzare l'elenco delle aziende, indicando il CAP della città in cui hanno sede
SELECT nomeAzienda, CAP 
FROM aziende;

-- 56 visualizzare l'elenco delle aziende, e per ognuna indicare il nome della città in cui hanno sede, il CAP e la provincia
SELECT nomeAzienda, citta, provincia, aziende.CAP 
FROM aziende JOIN citta ON aziende.CAP = citta.CAP;

-- 57 visualizzare l'elenco dei privati e per ognuno il CAP della città di residenza
SELECT cognome, nome, CAP 
FROM privati;

-- 58 visualizzare l'elenco dei privati e per ognuno il CAP, il nome e la provincia della città in cui risiedono
SELECT cognome, nome, citta, provincia, privati.CAP 
FROM privati JOIN citta ON privati.CAP = citta.CAP;

-- 59 visualizzare l'elenco delle città e per ogni città, nome dell'azienda che ha sede nella città, nome e cognome dei privati che risiedono nella città (fare attenzione a non visualizzare due volte le stesse informazioni)
SELECT citta, nomeAzienda, nome, cognome 
FROM citta JOIN aziende ON citta.CAP = aziende.CAP
JOIN privati ON citta.CAP = privati.CAP;

-- 60 visualizzare i privati che hanno un cognome iniziante con la lettera P oppure con la lettera A, indicando i codici delle inserzioni che questi hanno fatto
SELECT nome, cognome, idInserzione 
FROM privati JOIN inspriv ON privati.idPrivato = inspriv.idPrivato
WHERE (cognome LIKE "P%" OR cognome LIKE "A%");



-- ESERCITAZIONE 5

-- 61 ripetere il punto precedente visualizzando anche la categoria dell'inserzione
SELECT nome, cognome, idInserzione, nomeCategoria 
FROM privati JOIN inspriv ON privati.idPrivato = inspriv.idPrivato
JOIN inserzioni ON inspriv.idInserzione = inserzioni.codice
JOIN categorie ON inserzioni.categoria = categorie.idCategoria
WHERE cognome LIKE "P%" OR cognome LIKE "A%";

-- 62 ripetere il punto precedente visualizzando anche il testo delle inserzioni
SELECT nome, cognome, idInserzione, nomeCategoria, testo 
FROM privati JOIN inspriv ON privati.idPrivato = inspriv.idPrivato
JOIN inserzioni ON inspriv.idInserzione = inserzioni.codice
JOIN categorie ON inserzioni.categoria = categorie.idCategoria
WHERE cognome LIKE "P%" OR cognome LIKE "A%";

-- 63 visualizzare il nome dei privati e il nome delle testate in cui i privati hanno pubblicato delle inserzioni;
SELECT CONCAT(privati.cognome, " ", privati.nome) AS Privato, testate.nome AS Testata
FROM privati JOIN inspriv ON privati.idPrivato = inspriv.idPrivato
JOIN instest ON inspriv.idInserzione = instest.idInserzione
JOIN testate ON instest.idTestata = testate.idTestata;

-- 64 visualizzare il nome dei privati, il nome delle testate in cui i privati hanno pubblicato delle inserzioni, i nomi dei comitati di redazione che dirigono le testate visualizzate
SELECT CONCAT(privati.cognome, " ", privati.nome) AS Privato, testate.nome AS Testata, nomeComitato
FROM privati JOIN inspriv ON privati.idPrivato = inspriv.idPrivato
JOIN instest ON inspriv.idInserzione = instest.idInserzione
JOIN testate ON instest.idTestata = testate.idTestata
JOIN redazioni ON testate.redazione = redazioni.idRedazione;


-- 65 visualizzare l'interrogazione al punto precedente indicando anche i nomi di tutti i redattori presenti nelle testate giornalistiche
SELECT CONCAT(privati.cognome, " ", privati.nome) AS Privato, testate.nome AS Testata, nomeComitato, CONCAT(redattori.cognome, " ", redattori.nome) AS Redattore
FROM privati JOIN inspriv ON privati.idPrivato = inspriv.idPrivato
JOIN instest ON inspriv.idInserzione = instest.idInserzione
JOIN testate ON instest.idTestata = testate.idTestata
JOIN redazioni ON testate.redazione = redazioni.idRedazione
JOIN redazRedat ON redazioni.idRedazione = redazRedat.idRedazione
JOIN redattori ON redattori.idRedattore = redazRedat.idRedattore;

-- 66 effettuare l'interrogazione al punto precedente visualizzando solo i privati il cui cognome inizia con la lettera p oppure con la lettera a
SELECT CONCAT(privati.cognome, " ", privati.nome) AS Privato, testate.nome AS Testata, nomeComitato, CONCAT(redattori.cognome, " ", redattori.nome) AS Redattore
FROM privati JOIN inspriv ON privati.idPrivato = inspriv.idPrivato
JOIN instest ON inspriv.idInserzione = instest.idInserzione
JOIN testate ON instest.idTestata = testate.idTestata
JOIN redazioni ON testate.redazione = redazioni.idRedazione
JOIN redazRedat ON redazioni.idRedazione = redazRedat.idRedazione
JOIN redattori ON redattori.idRedattore = redazRedat.idRedattore
WHERE privati.cognome LIKE "P%" OR privati.cognome LIKE "A%";

-- 67 Visualizzare il testo delle inserzioni presenti nelle categorie principali (quelle che non hanno categoria padre)
SELECT testo AS inserzioni
FROM inserzioni JOIN categorie ON inserzioni.categoria = categorie.idCategoria
WHERE categoriaPadre IS NULL;

-- 68 Visualizzare il numero delle inserzioni presenti nelle categorie principali;
SELECT count(*) AS numeroInserzioni
FROM inserzioni JOIN categorie ON inserzioni.categoria = categorie.idCategoria
WHERE categoriaPadre IS NULL;

-- 69 Modificare lo script relativo ad insAz in modo da aggiungere l'attributo costo nella tabella insAz
ALTER TABLE insaz
ADD COLUMN costo float;

-- 70 Inserire il costo delle inserzioni nella tabella insAz, variabile tra 30 e 50 euro;
UPDATE insaz
SET costo = FLOOR(RAND() * (50 - 30 + 1)) + 30;

-- 71 Visualizzare la spesa totale sostenuta dall'azienda con codice 'COM000' per pubblicare le inserzioni
SELECT SUM(costo) AS costoInserzioni
FROM insaz JOIN aziende ON insaz.idAzienda = aziende.idAzienda
WHERE aziende.idAzienda = "COM000";

-- 72 Visualizzare tutte le informazioni sulle inserzioni pubblicate;
SELECT *
FROM inserzioni;

-- 73  Visualizzare il numero totale delle inserzioni pubblicate
SELECT COUNT(*) AS numeroArticoli
FROM inserzioni;

-- 74 Visualizzare le inserzioni che hanno all'interno del testo la stringa 'affa'
SELECT testo
FROM inserzioni
WHERE testo LIKE "%affa%";

-- 75 Visualizzare il numero di inserzioni che hanno all'interno del testo la stringa 'affa'
SELECT COUNT(*)
FROM inserzioni
WHERE testo LIKE "%affa%";

-- 76 Visualizzare codice e costo delle inserzioni totali (utilizzare l'operatore UNION tra tabella insAz e insPriv)
SELECT idInserzione, costo
FROM insAz
UNION
SELECT idInserzione, NULL
FROM insPriv;

-- 77 Visualizzare il numero delle inserzioni totali (utilizzare l'operatore UNION tra tabella insAz e insPriv)
SELECT COUNT(*)
FROM (
    SELECT idInserzione
    FROM insAz
    UNION ALL
    SELECT idInserzione
    FROM insPriv
) AS subquery;

-- 78 Visualizzare il numero di inserzioni di privati e il numero di inserzioni di aziende
SELECT COUNT(*) AS inserzioniPrivati
FROM insPriv
UNION ALL
SELECT COUNT(*) AS inserzioniAziende
FROM insAz;

-- 79 Mostrare quante inserzioni ci sono per ogni categoria.
SELECT categoria, COUNT(*) AS numero_inserzioni
FROM inserzioni
GROUP BY categoria;

-- 80 Visualizzare le inserzioni che appartengono a più di una categoria.
 /*
 Questa interrogazione non è possibile 
 poiché ogni inserzione appartiene
 ad una e una sola categoria
 */