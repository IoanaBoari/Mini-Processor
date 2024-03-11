# Mini-Processor
	BOARI IOANA 312CD						

							Tema3 - README
Task1:
	In acest task se primeste ca data de intrare un nr, ce reprezinta o instructiune.
	Cu ajutorul operatiilor pe biti se extrag informatiile necesare din instructiune si se afiseaza in formatul cerut.
	Se interpreteaza primii 4 biti ai instructiunii pentru a afla nr N ce reprezinta nr de operatii.
	Cu ajutorul unei masti, acesti biti se reseteaza, valoarea lor devenind 0.
	Pentru a ma asigura ca nu pierd date am preferat sa lucrez cu o copie a instructiunii.
	Se interpreteaza cei 2*N biti pentru cele N operatii si se afiseaza.
	Acesti biti se reseteaza.
	Apoi se interpreteaza si urmatorii 4 biti pentru a afla dimensiunea unui operand.
Task2:
	Se interpreteaza instructiunea exact ca la taskul 1 dar acum nu se mai afiseaza datele.
	Folosesc variabila nr pentru a afla cate nr trebuie introduse si le citesc, salvand nr intr-un vector.
	De asemenea, si in acest caz am preferat sa lucrez cu o copie a acestui vector.
	In acest caz Dim poate avea doar valori divizibile cu 16, astfel un operand nu se poate intinde pe 2 nr introduse.
	Am folosit variabila r pentru a afla cati operanzi reies din fiecare nr introdus.
	Folosind operatii pe biti, am extras fiecare operand din fiecare nr introdus pe rand si l-am stocat in vectorul operanzi[].
	In final, am interpretat operatiile in ordine, fara a tine cont de precedenta, si am afisat rezultatul.
Task3:
	Se foloseste codul de la taskul2, dar operanzii se extrag diferit in cazul in care Dim nu este divizor al lui 16.
	In acest caz se folosesc operatii pe biti pentru a se alatura bitii a 2 nr consecutive.
Task4:
	Se foloseste codul de la taskul2, dar se schimba modul in care sunt executate operatiile.
	Se tine cont de precedenta operatorilor, asadar mai intai se fac operatiile de * si /.
	Dupa fiecare operatie valoarea rezultata este atribuita primului operand din operatie, iar al doilea este scos din vectorul operanzi[].
	Totodata, dupa fiecare operatie, aceasta este scoasa din vectorul opr[].
	Apoi se executa si + - in ordinea in care apar.
	In final se afiseaza rezultatul.
	
