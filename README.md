# Baby-Shark
Codage de la commande "SUDO" en C

L'objectif de ce projet était d'écrire notre propre version (simplifiée) de la commande sudo. Tout comme la commande originale, le programme peut exécuter une commande en tant qu'un autre utilisateur (par défaut, root).



|                   Utilisation de "Whoami"                   |                                                    Utilisation de "Whoami"                                                     |
|:-----------------------------------------------------------:|:------------------------------------------------------------------------------------------------------------------------------:|
| Sans sudo nous avons en retour le nom de notre utilisateur. | Dans le cas où nous faisons notre sudo soit `./Baby_shark` et whoami nous obtenons root nous sommes donc en super utilisateur. |
|            ![](https://i.imgur.com/URLBWhV.png)             |                                              ![](https://i.imgur.com/67w9NKD.png)                                              |

Option de changement d'utilisateur avec Whoami. Dans le cas comme ci dessous, où l'utilisateur demandé n'existe pas nous obtenons le message d'erreur `unknoxn user`.
| ![](https://i.imgur.com/4nc7auW.png) | ![](https://i.imgur.com/FM429Ml.png) |
| ------------------------------------ | ------------------------------------ |
   
   
    
En revanche dans le cas où l'utilisateur demandé est bien existant nous avons en retour, le nom de l'utilisateur. Par ailleurs, l'accès aux fonctionnalités  accordées par le biais de l'utilisation de `sudo` est bien protégé car on peut y accéder qu'une fois notre mot de passe utilisateur (celui demandé pour utiliser le véritable sudo) saisi.



| ![](https://i.imgur.com/VmV1yhB.png) | ![](https://i.imgur.com/zdOJ1h8.png) |
| ------------------------------------ | ------------------------------------ |




