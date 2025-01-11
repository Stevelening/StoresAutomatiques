# Wiki STOMAT

## Description du projet
STOMAT est un store Automatique, qui se ferme et s'ouvre en fonction de la luminosité. Il dispose aussi de commande manuel.

### L'équipe:
- Grathwohl Hugo
- Lening Talaupa Zidane Steve
- Saffo Tadaah Ange Leila
- Theubo Berger Ghislain

## Problématique
```
problématique liée à votre projet et en quoi votre projet est tellement bien que vous y répondez (même en partie)
```
    

## Matériel
```
Matériel utilisé
```
- une Arduino uno
- un capteur de lumière
- un module bluetooth HC-05
- un servo moteur
- une breadboard qui était coupé en deux
- des fils de connections
- une structure en bois découpé au laser
- on a utilisé les chutes pour compléter cette structure
- 2 axes en métal
- 2 bars en métal
- élément de l'axe en PMMA découpé au laser
- un ressort
- une cartouche d'encre vide

## Utilisation
```
scénario d’utilisation : à vous de choisir la structure des sous-sections
    - c’est ici que vous décrivez en détail ce que votre projet fait, 
    - comment il fonctionne, 
    - avec à l’appui captures d’écran et vidéo(s) de démonstration
```

### Connection à la carte
Pour configurer le store, il faut d'abord se connecter en bluetooth:
```
décrire ici comment faire
```

Une fois connecté le store dispose de 2 modes.
### Mode manuel
Le mode manuel dispose de 2 commande:
- Store en position haute: envoyer 'mu' à la carte pour "manuel up"
    ```
    ajout de photo
    ```
- Store en position basse: envoyer 'md' à la carte pour "manuel down"
    ```
    ajout de photo
    ```

### Mode automatique
Le mode automatique répond à la luminosité du capteur. Il est conseillé de l'attacher contre une fenètre.

Si le capteur y est exposé, le store va alors se fermer.
```
ajout de photo
```
Si le capteur retourne à l'ombre, le store va s'ouvrir.
```
ajout de photo
```


## Budget
```
budget approximatif : matériel + temps de travail (cohérent avec votre planning réel);
```
- Cout matériel:
- Temps de travail:

## Bilan
- bref bilan : vous avez répondu à la problématique, même en partie;
Dans l'ensemble nos objectifs par rapport a ce projet ont ete atteints initialement on avait pour objectif de faire des stores automatiques permettant en fonction d'une simple commande de pouvoir faire monter ou descendre les stores . Dans nos recherches on s'est rendu compte qu'onj pouvait le rendre aussi manuel en fonction de notre sensibilite au soleil ce qui rendait encore sa presence encore plus ineluctable dans notre vie au quotidien...

## Future
- future works étendu : au cours du projet
 
    On aurait peut etre pu ajouter la faculte a ce que ce dernier s'arrete lors de sa descente ou de sa montee  ou a quelle vitesse il doit aller dans un sens comme dans l'autre mais cet ensemble d'etapes et enfin modifier le seuil auquel le store s'arrete lors de son mouvement , ameliorer l'arbre moteur encore instable, une alimentation branchee sur secteur au lieu des cables connectes . En effet, tout cela constitue une version ulterieure de notre projet (avec des ressources et un temps plus consequent) .Un prototype en taill reele pouvant etre implemente au quotidien

    On aurait pu faire une application web et mobile permettant la connexion et la configuration du store automatique a distance.

Ceci peut bien evidemment etre commercialiser si cela est fait a une echelle reelle et avec toutes les fonctionnalites non implementees.
