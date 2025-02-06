# Projet Voltaire  

**Projet Voltaire** est une application console en C++ qui corrige l'orthographe d'un texte extrait d'une zone définie de l'écran sous Windows.  
Il utilise cURL, nlohmann et l'API Tesseract.

## Fonctionnalités  
- Extrait le texte d'une zone de l'écran en boucle.  
- Envoie ce texte à différentes API pour détecter et corriger les erreurs.  
- Affiche les résultats dans le terminal.  
- Précision estimée à ~90% minimum (vérification manuelle recommandée). 

## Installation  
1. Téléchargez le fichier `.exe` ou compiler le projet.
2. Placez le fichier `fra.traineddata` (Tesseract) dans le même dossier que l'exécutable.  

## Utilisation  
1. Lancez le programme.  
2. Sélectionnez la zone de l'écran à capturer à l'aide de deux clics.  
3. Consultez les corrections dans le terminal à chaque fois qu'un nouveau texte apparaît.

Vidéo explicative : https://youtu.be/BtBTKDrvUZg

## Notes  
- Compatible uniquement avec **Windows**.  
- Projet en cours : contributions et signalements de bugs bienvenus !  

## API actuelles
- Reverso
- LanguageTool
