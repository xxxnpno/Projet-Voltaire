# Projet Voltaire

**Projet Voltaire** est un logiciel en C++ conçu pour faciliter la correction orthographique en utilisant la reconnaissance de texte. Il extrait le texte d'une zone spécifique de l'écran et vérifie les erreurs d'orthographe grâce à l'API Reverso. Ce programme fonctionne exclusivement sous Windows et utilise les bibliothèques cURL, nlohmann et l'API Tesseract pour l'extraction et la correction de texte.

## Fonctionnalités

- **Extraction de texte** : Capture du texte à partir d'une zone définie de l'écran toutes les 500 ms.
- **Correction orthographique** : Envoi du texte extrait à l'API Reverso pour la détection et la correction des erreurs d'orthographe.
- **Affichage des erreurs** : Les erreurs d'orthographe sont affichées directement dans le terminal pour permettre une correction rapide.
- **Langue supportée** : Le programme fonctionne uniquement en français.
- **Garantie de réussite** : Taux de précision estimé à 80%. Des erreurs peuvent subsister, il est donc conseillé de vérifier les résultats.

## Installation

1. Téléchargez et placez le fichier `.exe` dans le dossier de votre choix.
2. Assurez-vous d'avoir le fichier `fra.traineddata` (fichier de langue nécessaire pour Tesseract) dans le même dossier que l'exécutable.

## Utilisation

1. **Lancez l'exécutable** : Exécutez le fichier `.exe` pour démarrer le programme.
2. **Définissez la zone de capture** : Sélectionnez une zone spécifique de l'écran à partir de laquelle le texte sera extrait toutes les 500 ms.
3. **Correction automatique** : Le texte extrait est envoyé à l'API Reverso pour être corrigé.
4. **Vérification des erreurs** : Les erreurs d'orthographe sont affichées directement dans le terminal pour être consultées et corrigées.

## Remarques

- Le programme est conçu pour fonctionner uniquement sous **Windows**.
- Bien que la précision soit élevée, il reste possible que des erreurs surviennent dans certains cas. **Vérifiez toujours les résultats** pour une correction optimale.
- Le projet est en développement continu. N'hésitez pas à **contribuer**, à signaler des bugs ou à proposer des améliorations.

## Contribution

Vous pouvez contribuer au projet en **soumettant des issues** pour signaler des bugs ou en proposant des **pull requests** pour ajouter de nouvelles fonctionnalités ou améliorer les performances.
