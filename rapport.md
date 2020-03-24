# SPACE_INVADERS 
### par Aymée Bonvarlet

** https://github.com/aymeebonvarlet/Space_invaders **

## Mode d’emploi

* Cloner le fichier GitHub
* Ouvrir le projet sur Atollic TrueStudio
* Brancher la carte STM32 sur USB UART et STM32F407G-DISC1
* Ouvrir un terminal et taper la commande : screen /dev/ttyUSB* 115200
* Lancer le projet sur Atollic TrueStudio 
* I pour aller à droite
* A pour aller à gauche
* Espace pour tirer 

## Mes difficultés 

### Se lancer

Le plus compliqué a été de se lancer en ayant une bonne vision du projet. 
J’ai d’abord voulu avoir deux types de monstres, un menu magnifique, utiliser l’accéléromètre de la STM32, le bouton poussoir, avoir des niveaux, un choix du clavier BÉPO ou AZERTY et bien d’autres...

Puis finalement, je me suis dit qu’un type de monstre était suffisant car nos jeux ne seront pas commercialisés. En effet, ce projet sert à développer nos compétences. Cela a aussi eu une incidence sur mes niveaux : je n’en ai pas fait. 

J’ai du coup préféré la qualité à la quantité. 

Entre temps, j’avais déjà créé mes fichiers. Puis j’ai arrêté et pris une feuille en y inscrivant un schéma. 
Ce schéma relie les big_monsters, mon héros, les shoots et le main. De plus, j'y ai inscrit les fonctions dont j’aurai besoin. Le but étant de ne pas avoir de fonctions dans tous les sens mais bel et bien une lecture claire de nos fichiers et de leurs utilisations.

### Coordonnées des héros/monstres/shoots

Il fallait que chacun est une coordonnée en x et y. J’ai d’abord pensé aux pointeurs à deux dimensions. Mais pour la lisibilité j’ai préféré des tableaux à deux dimensions. 
Mes 10 big_monsters : tab_bm[ID][x,y]
Mon héro : tab_myspace[x,y]
Mes shoots: tab_shoot[x,y] , tab_shootbm[x,y]

### Variables

Il fallait créer des variables, un bon nombre d’ailleurs, lisibles, accessibles dans tous les fichiers, mais modifiables que dans certains. J’ai donc créé des getter et setter sur TOUTES mes variables permettant de débugger de façon claire. Cela a changé ma façon de programmer puisque je n’avais jamais créé de jeu ou de gros dossier demandant autant de rigueur sur les variables. En effet, notre projet en robotique était en Python3 et M. Fabre n’avait pas mis l’accent sur l’accessibilité des variables. Il est vrai, que le débug était plus complexe. Ce VS Code est plus agréable à utiliser.

## Notions Apprises/Découvertes

Ce projet m’a permis d’approfondir mes méthodes de codage en C:

- Commentaires pour améliorer la lisibilité
- Getter Setter pour débugger et améliorer la lisibilité
- Faire avancer que d’un pas chaque fonction dans une boucle while (1), ce que fait Windows. Je n’en avais pas connaissance auparavant. 
- Si une fonction ne prend pas de paramètre, lui mettre à la place : void
- l’utilisation des uint8_t,uint16_t,uint32_t
- Utiliser Git de façon fonctionnelle et claire. Auparavant, je n’avais qu’une utilisation non exhaustive, alors que dans ce projet je l’ai utilisé de façon systématique.
- Utiliser les fonctions serial_get_last_char(), vt100_move(),serial_puts() et serial_putchar() qui permette de faire le lien avec la carte STM32.

## A regarder

J'aimerais connaître quels sont les points que j’aurais pu améliorer, perfectionner, ou approfondir afin de rendre mon code plus performant ou simplement meilleur. 

## Retour d’expérience général

J’ai adoré réaliser ce projet, car ce que j’aime pas dessus tout dans l’embarqué c’est de voir réellement lorsque nos codes sont fonctionnels : voir les liens entre les objets et le code. 
J’ai réellement apprécié votre implication pour chacun de nous. 

Le seul bémol est que j’aurais réellement apprécié que l’on apprenne à utiliser l’accéléromètre de la carte ainsi que ses autres fonctionnalités. J’aurais vraiment adoré que la carte devienne la manette de jeu de mon SPACE_INVADERS. 