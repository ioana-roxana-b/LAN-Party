build:
	 g++ -o lanParty main.cpp player.cpp echipa.cpp lista.cpp coada_meciuri.cpp stiva_castigatori.cpp stiva_invinsi.cpp last8.cpp BST.cpp AVL.cpp solutii.cpp
run:
	./lanParty c.in d.in r.out
clean:
	rm -f lanParty castigatori.out date_coada.out
