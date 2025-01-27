# Bibliothécaire Leila

**Bibliothécaire Leila** est un jeu de bureau simple où le but est d’aider la bibliothécaire à organiser ses livres en différentes catégories. Il a été développé en C++ et utilise la bibliothèque SFML pour les graphiques et l’interaction utilisateur.

Le jeu comprend une série de classes:
Les classes Baselist.h, List.h et Stack constituent la base du fonctionnement des jeux.

## Configuration requise

Avant l’installation, assurez-vous que votre environnement répond aux exigences suivantes :

- **Système d’exploitation :** Linux (testé sur Ubuntu 22.04 ou une version ultérieure).
- **Compilateur :** g++ ou un autre compatible avec C++17.
- **Bibliothèques :** SFML et libpqxx. Vous pouvez installer les dépendances avec la commande suivante :
  ```bash
  sudo apt-get install libsfml-dev libpqxx-dev

## Installation
Actuellement, aucune distribution de paquets n’est disponible. La seule façon d’installer le jeu est via le code source.

1. Clonez le dépôt
Téléchargez le code source directement depuis GitHub :

```bash
$ git clone https://github.com/luana-q-g/bibliothecaire-leila.git
```

2. Accédez au dossier du projet
Allez dans le répertoire où le dépôt a été cloné :

```bash
$ cd bibliothecaire-leila
```

3. Compilez le jeu
Utilisez la commande make pour compiler le jeu. Le fichier Makefile est déjà configuré pour générer l’exécutable :

```bash
$ make
```

4. Lancez le jeux
Une fois compilé, vous pouvez lancer le jeu avec la commande suivante :

```bash
$ ./bibliothecaire-leila
```
