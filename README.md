# Projet Voltaire  

**Projet Voltaire** est un logiciel en C++ qui corrige l'orthographe du texte extrait d'une zone définie de l'écran sous Windows. Il utilise cURL, nlohmann, et l'API Tesseract, ainsi que l'API Reverso pour les corrections.

## Fonctionnalités  
- Capture du texte d'une zone d'écran toutes les 500 ms.  
- Envoi à l'API Reverso pour détection et correction des erreurs.  
- Résultats affichés dans le terminal.  
- Précision estimée à 80% (vérification manuelle recommandée).  

## Installation  
1. Téléchargez le fichier .exe.  
2. Placez le fichier `fra.traineddata` (Tesseract) dans le même dossier que l'exécutable.  

## Utilisation  
1. Lancez le programme.  
2. Sélectionnez la zone d'écran à capturer.  
3. Consultez les corrections dans le terminal.  

## Notes  
- Compatible uniquement avec **Windows**.  
- Projet en cours : contributions et signalements de bugs bienvenus !  
