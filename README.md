<<<<<<< HEAD
**UltimateIO V1.0 - Spécifications générales**

**Partie informatique**

**Général**


L'application sera développée en C++ via Qt afin d'assurer une portabilité entre les différents systèmes d'exploitation.
Pour coordonner les différentes parties de l'application, une table des variables sera présente. Elle permettra par exemple de recevoir des informations via un script ou une commande et les afficher sur le dashboard. Ces variables seront soit des variables physiques, donc liées à l'UltimateIO, soit des variables internes servant à sauvegarder des informations ou à effectuer des opérations.

**Dashboard**

Le dashboard permettra de visualiser et d'agir l'état du système (entrées, sorties, variables, etc.) de manière entièrement graphique. 

Les différents composants seront déposés sur le dashboard via un glissé/déposé.

Parmi ces composants on retrouvera :
- des LEDs
- des boutons poussoirs
- des interrupteurs 
- des afficheurs de texte
- des jauges
- des potentiomètres (rotatifs et linéaires) 
- des traceurs de courbes (type oscilloscope)

Le taux rafraichissement du dashboard sera configurable par l'utilisateur.

Les éléments du dashboard pourront être sauvegardés dans un fichier afin de 	pouvoir les restaurer par la suite.

**Interface ligne de commande**


Cette interface permettra de configurer et de commander directement l'UltimateIO via des commandes textuelles simples. Ces commandes permettront de :
Lire des entrées (numériques et analogiques)
Écrire des sorties (numériques et analogiques)
Générer des signaux PWM
Envoyer et recevoir des données via les liaisons intégrées(radio, I2C, SPI, USART)
Configurer le rôle d'une broche
D'effectuer des opérations mathématiques entre variables et/ou valeurs numériques
	
Un historique des commandes sera accessible.

**Éditeur de scripts**


L'éditeur de script permettra d'exécuter une liste d'instructions prédéfinies.
Ces instructions seront les mêmes que celle disponible via la ligne de commande avec quelques ajouts : 
possibilité de créer des boucles
utilisation de pauses

L'utilisation de macros sera également disponible.

**Configuration**


Cette section aura pour but de configurer le rôle de chaque broche de l'UltimateIO.
Il sera possible d'appliquer cette configuration à la volée et de la sauvegarder dans un fichier ou directement dans l'UltimateIO afin qu'il se configure automatique à sa mise sous tension. 
Il sera aussi possible de récupérer la configuration enregistrée dans l'UltimateIO ou dans un fichier afin de ne modifier que le nécessaire.


**Partie électronique**



**Application**


**Coeur du système**

Le système sera basé sur le système temps réel FreeRTOS.  L'accès aux périphériques se fera via le DMA lorsque cela est possible afin de ne pas surcharger le processeur.

**Liaison USB**

L'utilisation de la norme HID permettra une utilisation de l'UltimateIO sans l'installation préalable de drivers. 
Plusieurs endpoints seront créés dans le but de séparer les données en fonction de leur type et de leur sens.
Un numéro de série unique devra être donnée à chaque UltimateIO pour pouvoir en connecter plusieurs sur la même machine.

**Traitement des instructions**

Chaque instruction sera ajoutée dans une liste de type FIFO.
Une tâche aura pour rôle de récupérer le contenu de cette liste et d'en exécuter chaque instruction de manière séquentielle. 

**Gestion du dashboard**

Le dashboard requiert un rafraichissement périodique des données, une tâche lui sera donc consacrée. 
Elle pourra être mise en pause lorsque le dashboard ne sera pas au premier plan du logiciel de contrôle, cela minimisera l'utilisation de la bande passante.


**Implantation matérielle**


Le microcontrôleur utilisé sera de la famille des STM32. 
Un module nRF24L01+ sera implanté afin de mettre en place une communication sans-fil native.
Une mémoire EEPROM sera utilisée pour permettre la sauvegarde de la configuration de l'UltimateIO.
Une LED témoin pilotable par l'utilisateur sera présente sur l'UltimateIO. 
Un connecteur permettra de connecter un module d'extension (ou plusieurs via un système de chainage) à l'UltimateIO.  Cela aura pour but de créer un système prêt à l'emploi (interface de puissance par exemple).


**Améliorations possibles**


**Mise à jour du firmware**

Dans le but d'apporter de nouvelles fonctionnalités ou de corriger celles existantes, une possibilité de mise à jour du firmware de l'UltimateIO via l'application peut être envisagée.

**Connexion ethernet**

Il serait possible d'ajouter une connectivité ethernet en plus de la connexion USB afin d'utiliser un nombre plus important de modules ou de les piloter à distance.
L'ajout en plus d'une interface web permettrait d'utiliser l'UltimateIO à partir de n'importe quel appareil connecté sur le même réseau que celui-ci (ordinateur, smartphone, tablette).
=======
UltimateIO
==========
>>>>>>> efadf70a886205fe77e924dd509e91fbd55c27d3
