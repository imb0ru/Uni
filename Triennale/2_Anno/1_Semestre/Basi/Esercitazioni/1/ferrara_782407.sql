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