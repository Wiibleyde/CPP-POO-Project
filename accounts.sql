PRAGMA foreign_keys=OFF;
BEGIN TRANSACTION;
CREATE TABLE accounts(idAccount INTEGER PRIMARY KEY AUTOINCREMENT,login TEXT, password TEXT, sex INTEGER);
INSERT INTO accounts VALUES(1,'arno','arno',0);
INSERT INTO accounts VALUES(2,'nay','nay',0);
INSERT INTO accounts VALUES(3,'alexandre','alexandre',0);
INSERT INTO accounts VALUES(5,'arno2','arno2',NULL);
INSERT INTO accounts VALUES(6,'nathan','nathan',NULL);
INSERT INTO accounts VALUES(7,'guillaume','guillaume',NULL);
INSERT INTO accounts VALUES(8,'quentin','quentin',NULL);
CREATE TABLE aime (
	idAime INTEGER PRIMARY KEY,
	idAccount INTEGER,
	libelle TEXT not NULL,
	FOREIGN KEY(idAccount) REFERENCES accounts(idAccount));
INSERT INTO aime VALUES(1,1,'Bricolage');
INSERT INTO aime VALUES(2,2,'Lecture');
INSERT INTO aime VALUES(4,1,'Science-Fiction');
INSERT INTO aime VALUES(5,3,'Sudoku');
INSERT INTO aime VALUES(6,3,'Lecture');
INSERT INTO aime VALUES(7,1,'Musique');
INSERT INTO aime VALUES(8,6,'Coder');
INSERT INTO aime VALUES(9,7,'Poupouilles');
DELETE FROM sqlite_sequence;
INSERT INTO sqlite_sequence VALUES('accounts',8);
-- create a model with aime for one account
CREATE VIEW v_aime AS SELECT idAccount,libelle from accounts;
COMMIT;
