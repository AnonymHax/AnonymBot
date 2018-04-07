# AnonymBot

Ceci est l'ancien projet AnonymBot, étant un bot socket Dofus 2.0, réalisé par G0hu et moi (AnonymHax)

Voici ses fonctionnalités:

- Metiers
- IA de combat
- Systeme de scripts pour les combats / métiers
- Système de groupe 
- Follow
- Gestion de caractéristiques / sorts
- Flood
- Echange
- Système de groupe
- Système de réponse humaine (CleverBot)
- Bypass des securités anti-bot (ayant changées depuis l'arret du projet)

Certaines fonctionnalités étaient encore à explorer et finir, mais pourront aider certains dans la mise en oeuvre de leur propres bots

Le projet se divise en 3 parties:

AnonymBot : le bot réalisé en C++ / Qt avec QML pour l'interface
SlaveMaker: Le serveur en C++ / Qt gérant les abonnements premium/gratuit pour utiliser le bot (le bot n'est plus commercialisé désormais), et gerant les échanges avec un client Dofus injecté pour bypass certaines sécurités anti-bot (révolu)
CodeGenerator: Traducteur automatique des protocoles du code-source du jeu en AS3 vers notre propre protocole en C++

Avant son arret, le bot subissait une refonte de son interface graphique en QML, bien que la majorité des fonctionnalités étaient achevées, ainsi l'interface actuelle ne represente qu'une petite partie de ses capacités. Certains anciens screenshots permettent d'entrevoir toutes les capacités.

Screenshots:
 
Interface de selection des differents comptes, avec vue générale (UI QML):
 
![image](https://github.com/AnonymHax/AnonymBot/blob/master/screenshots/screen2.png?raw=true)

Chat principal, et interface de commande (UI QML):

![image](https://github.com/AnonymHax/AnonymBot/blob/master/screenshots/screen3.png?raw=true)

Representation simplifiée de la carte courante et des éléments interactifs (UI QML):

![image](https://github.com/AnonymHax/AnonymBot/blob/master/screenshots/screen4.png?raw=true)
![image](https://github.com/AnonymHax/AnonymBot/blob/master/screenshots/screen5.png?raw=true)
![image](https://github.com/AnonymHax/AnonymBot/blob/master/screenshots/screen6.png?raw=true)

Chat principal, et interface de commande (UI QT): 

![image](https://github.com/AnonymHax/AnonymBot/blob/master/screenshots/screen7.png?raw=true)

Gestion inventaire (UI QT):

![image](https://github.com/AnonymHax/AnonymBot/blob/master/screenshots/screen8.png?raw=true)

Gestion caracteristiques (UI QT):

![image](https://github.com/AnonymHax/AnonymBot/blob/master/screenshots/screen9.png?raw=true)

Gestion flood/échange/réponse humaine - CleverBot (UI QT):

![image](https://github.com/AnonymHax/AnonymBot/blob/master/screenshots/screen10.png?raw=true)

Gestion combat:

![image](https://github.com/AnonymHax/AnonymBot/blob/master/screenshots/screen11.png?raw=true)

Informations sur la qualité de la connexion socket:

![image](https://github.com/AnonymHax/AnonymBot/blob/master/screenshots/screen12.png?raw=true)


Autres fonctionnalités sans screenshots présentes



