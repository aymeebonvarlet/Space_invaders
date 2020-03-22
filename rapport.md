# SPACE_INVADERS 
### par Aymée Bonvarlet

** https://github.com/aymeebonvarlet/Space_invaders **

## Mode d’emploi

* Ouvrir le projet sur Atollic TrueStudio
* Brancher la carte STM32 sur USB UART et STM32F407G-DISC1
* Ouvrir un terminal et taper la commande : screen /dev/ttyUSB* 115200
* Lancer le projet sur Atollic TrueStudio 
* I pour aller à droite
* A pour aller à gauche
* Espace pour tirer 

## Mes difficultés 

### Se lancer

Le plus compliqué à été de se lancer en ayant une bonne vision du projet. 
J’ai d’abord voulu avoir 2 types de montres, d’où l’appel: big_monsters. Puis finalement je me suis dis qu’un type de montres était suffisant car nos jeux ne seront pas commercialisés, mais ne sert qu’à développer nos compétences. J’ai du coup préférer la qualité à la quantité. 

Entre temps j’avais déjà créer mes fichiers, puis j’ai arrêté et pris une feuille en y inscrivant un schéma. 
Schéma reliant les big_monsters, mon héro, les shoots et le main. Tout en y inscrivant les fonctions dont j’aurai besoin. Afin de ne pas avoir des fonctions dans tous sens mais bel est bien une lecture claire de mos fichiers et de leurs utilisation.

J’ai alors réaliser quelque chose : la créatior des gros jeux vidéos doit être longue est pourvu de complication car il faut que tout soit bien étudier.

### Coordonnées des héros/monstres/shoots

Il fallait que chacun est une coordonnées en x et y. J’ai d’abord penser aux pointeurs à deux dimensions. Mais pour la lisibilité j’ai préféré des tableaux à deux dimensions. 
Mes 10 big_monsters : tab_bm[ID][x,y]
Mon héro : tab_myspace[x,y]
Mes shoots: tab_shoot[x,y] , tab_shootbm[x,y]

### Variables

Il fallait créer des variables, un bon nombre d’ailleurs, lisibles, accessibles dans tous les fichiers, mais modifiable que dans certain.









