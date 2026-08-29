# C Mini Projects

Trois applications **console en C**, réalisées pendant la période SAS chez YouCode.  
Compilées avec **Code::Blocks** et **MinGW** sous Windows.

| | |
|---|---|
| Langage | C (C99) |
| Environnement | Windows |
| IDE | [Code::Blocks](https://www.codeblocks.org/) + GCC / MinGW |

---

## Sommaire

- [Aperçu](#aperçu)
- [Mini-projets](#mini-projets)
  - [01 — Calculatrice](#01--calculatrice)
  - [02 — Gestion de librairie](#02--gestion-de-librairie)
  - [03 — Carnet de contacts](#03--carnet-de-contacts)
- [Prérequis](#prérequis)
- [Compilation et exécution](#compilation-et-exécution)
- [Structure du dépôt](#structure-du-dépôt)
- [Historique](#historique)

---

## Aperçu

| Projet | Dossier | Source | Rôle |
|--------|---------|--------|------|
| Calculatrice | [`Mini_Projet_01/`](Mini_Projet_01/) | `Calculator.c` | 8 opérations arithmétiques |
| Gestion de librairie | [`Mini_Projet_02/`](Mini_Projet_02/) | `Library.c` | Stock de livres en mémoire |
| Carnet de contacts | [`Mini_Projet_03/`](Mini_Projet_03/) | `Contacts.c` | Carnet basé sur une `struct Contact` |

---

## Mini-projets

### 01 — Calculatrice

**Fichiers :** [`Calculator.c`](Mini_Projet_01/Calculator.c) · [`Calculator.cbp`](Mini_Projet_01/Calculator.cbp)

Calculatrice interactive en boucle (continuer ou quitter après chaque opération).

- Addition et multiplication de plusieurs nombres
- Soustraction et division de deux nombres
- Moyenne d’une série
- Valeur absolue, exponentiation, racine carrée

> La racine carrée (`sqrt`) nécessite la bibliothèque mathématique (`-lm`), déjà liée dans le projet Code::Blocks.

### 02 — Gestion de librairie

**Fichiers :** [`Library.c`](Mini_Projet_02/Library.c)

Gestion d’un stock de livres en mémoire (titre, auteur, prix, quantité).

- Ajouter un ou plusieurs livres
- Afficher le stock
- Rechercher par titre
- Mettre à jour une quantité
- Supprimer un livre
- Afficher le total en stock

### 03 — Carnet de contacts

**Fichiers :** [`Contacts.c`](Mini_Projet_03/Contacts.c) · [`Mini_Project_03.cbp`](Mini_Projet_03/Mini_Project_03.cbp)

Carnet de contacts (nom, téléphone, e-mail) avec menus imbriqués.

- Ajout simple ou multiple
- Affichage simple, tri croissant ou décroissant
- Modification, suppression et recherche par nom
- Statistique : nombre total de contacts

---

## Prérequis

- Windows
- [GCC / MSYS2](https://www.msys2.org/) (`gcc` dans le PATH)
- [Visual Studio Code](https://code.visualstudio.com/) + extension **C/C++** (Microsoft)

Les programmes utilisent `system("cls")`, `system("color")` et `system("pause")` : ils sont prévus pour **Windows uniquement**.

L’interface console est en **anglais** (ASCII) pour éviter les problèmes d’accents dans `cmd`.

---

## Compilation et exécution

### Avec Visual Studio Code

1. Ouvrir le dossier `C_Mini_Projects`.
2. Compiler : `Ctrl+Shift+B` (Calculator) ou **Terminal → Run Task…** (Library / Contacts).
3. Lancer dans le terminal : `.\Calculator.exe`, `.\Library.exe` ou `.\Contacts.exe`.

### En ligne de commande

```bash
gcc -Wall -Wextra -std=c99 Mini_Projet_01/Calculator.c -o Calculator -lm
gcc -Wall -Wextra -std=c99 Mini_Projet_02/Library.c -o Library
gcc -Wall -Wextra -std=c99 Mini_Projet_03/Contacts.c -o Contacts
```

---

## Structure du dépôt

```text
C_Mini_Projects/
├── .gitignore
├── README.md
├── .vscode/
│   ├── tasks.json
│   ├── c_cpp_properties.json
│   └── extensions.json
├── Mini_Projet_01/
│   ├── Calculator.c
│   └── Calculator.cbp
├── Mini_Projet_02/
│   └── Library.c
└── Mini_Projet_03/
    ├── Contacts.c
    └── Mini_Project_03.cbp
```

Les binaires (`.exe`, `.o`), dossiers `bin/` et `obj/`, et fichiers générés par Code::Blocks (`.depend`, `.layout`) sont ignorés via [`.gitignore`](.gitignore).

---

## Historique

| Projet | Date de création |
|--------|------------------|
| Mini Projet 01 | 26 septembre 2024 |
| Mini Projet 02 | 28 septembre 2024 |
| Mini Projet 03 | 02 octobre 2024 |
