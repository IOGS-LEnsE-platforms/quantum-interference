Pour le code python de l'interface, voici l'état d'avancement :
Nous avons un code principal qui appelle différents autres codes (le code interface_GRE).

La fenêtre principale de l'interface comporte : 
- 3 fenêtres qui affichent les coups sur les 3 voies en fonction du temps
- 3 fenêtres qui affichent les coïncidences AB AC ABC en fonction du temps
- Une fenêtre avec les jauges A, B, C, ABC pour le réglage grossier 
- Une fenêtre permettant de lancer l'acquisition, de modifier le temps d'intégration et la fenêtre de coïncidence. Attention, si on change le temps d'intégration il faut stopper l'acquisition et la relancer pour que le temps d'échantillonnage s'actualise en fonction. 

Normalement tout fonctionne ici sauf la commande permettant de sauvegarder les images des courbes affichées, je ne sais pas pourquoi.

Il y a ensuite des fenêtres secondaires, la première permet de contrôler le piezo tout fonctionne dessus sauf le déplacement automatique de 0à 20, mais on ne doit pas être loin d'un code qui marche car il fonctionnait lorsqu'il n'était pas sur l'interface et qu'on le testait de son côté, idéalement il faudrait ajouter un bouton pour choisir le pas de ce déplacement où le calibrer directement dans le code à 30 nm car c'est le pas que l'on utilisait pour tracer nos courbes.

La deuxième fenêtre est celle du G2 à 3 détecteurs l'affichage fonctionne mais les valeurs sont aberrantes, c'est le principal problème que l'on a et pour moi il n'est pas dû à l'interface, il est dû au trop faible nombre de coïncidence affiché sur une des 2 voies (AC il me semble) qui fait que dès que l'on a une valeur de coïncidence ABC non nulle on a une g2 qui vaut 20, 30,40.
Je voulais que l'on compare les valeurs de AC mesurée avec notre carte et les comparer à celle mesurées avec l'ancienne carte pour voir si c'est la fenêtre de détection de la nouvelle carte qui pose problème mais je n'ai pas eu le temps.
Pour cette partie de l'interface il faudrait aussi ajouter un affichage de la valeur exacte du g2, pas seulement sur la courbe, ce que nous avons oublié de faire.

La troisième fenêtre est le code g2 à 2 détecteurs mais nous ne l'avons pas codées, il faudrait se baser sur le code g2 à trois détecteurs en transmettant la liaison série qui est déjà ouverte dedans.

Enfin la dernière fenêtre est celle des jauges de réglage de précision avec les jauges de AB et AC dedans. Mael a aussi ajouté les jauges de AB et AC corrigées.

Attention il faut que le piezo soit allumé avant de lancer le code et il ne faut pas débrancher la liaison entre piezo et l'ordinateur avant d'avoir débranché l'alimentation du piezo. 

J'espère ne rien avoir oublié, si c'est le cas je vous enverrais un autre mail. Et bien sûr si vous avez une question n'hésitez pas à m'envoyer un mail même si je doute que je sois plus compétent que vous pour y répondre.
