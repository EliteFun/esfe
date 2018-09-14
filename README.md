# ESFE
## FRANÇAIS

### Comment Faire
1. Téléchargez une copie de SFML pour pour votre compilateur (vous allez peut-être devoir compiler SFML de la source) ( voir: https://www.sfml-dev.org/download/sfml/2.4.2/index-fr.php)
2. «Dé-zippez» le fichier téléchargé dans `SFML`
3. Déplacer le dossier `SFML` dans le même dossier que le projet (où il y a le fichier `CMakeLists.txt`)
4. Déblacer le dossier `cmake_modules` depuis `SFML` vers le dossier du projet
5. Configurez et générez le projet cmake comme un projet régulier

### License
1. Suivez les licenses de SFML et des dépendances (https://www.sfml-dev.org/license-fr.php)
2. Vous pouvez vendre des jeux créés avec ce logiciel, mais vous n'avez pas le droit de le vendre

### Notes
Pour l'instant, la librairie va créer un éxécutable. Vous devez déplacer les dll qui sont dans le dossier de SFML vers le dossier où il y a votre éxécutable.

Veuillez me contacter si vous avez besoin d'information

## ENGLISH

### How-to
1. Download a copy of SFML for your compiler (you might need to build it from source) ( see: https://www.sfml-dev.org/download/sfml/2.4.2/)
2. Un-zip SFML to `SFML`
3. Move the `SFML` folder into the same folder as the project (where the `CMakeLists.txt` file is)
4. Move the `cmake_modules` folder from `SFML` folder into the project folder
5. Configure and generate the project as a regular cmake project

### License
1. Follow the SFML and it's external library's licences (https://www.sfml-dev.org/license.php)
2. You can sell games created with this software, but you CANNOT sell this software in it's own

### Notes
For now, this library will create an executable file. You will need to move all the dll from the SFML folder to the folder where your executable is stored.

Please contact me if you need any clarifications
