#include "uincampus/saisie.hpp"
#include "uincampus/regles.hpp"
#include <iostream>
#include <sstream>
namespace uin {
namespace {
// espace de noms anonyme : fonctions internes a ce fichier (chapitre 4)
std::string lireLigne(std::string_view invite)
{
std::cout << invite;
std::string ligne;
std::getline(std::cin, ligne);
return ligne;
}
bool estEntierStrict(const std::string& texte, int& valeur)
{
std::istringstream flux{texte};
char reste{};
return (flux >> valeur) && !(flux >> reste);
}
bool estReelStrict(std::string texte, double& valeur)
{
for (char& c : texte) {
if (c == ',') { c = '.'; }
}
std::istringstream flux{texte};
char reste{};
return (flux >> valeur) && !(flux >> reste);
}
} // namespace
std::string lireTexte(std::string_view invite)
{
return lireLigne(invite);
}
int lireEntier(std::string_view invite, int min, int max)
{
while (std::cin) {
const std::string ligne = lireLigne(invite);
int valeur{};
if (!estEntierStrict(ligne, valeur)) {
std::cout << "Saisie invalide : entrez un nombre entier.\n";
} else if (valeur < min || valeur > max) {
std::cout << "La valeur doit etre comprise entre " << min << " et " << max << ".\n";
} else {
return valeur;
}
}
return min;
// fin d'entree : valeur de repli (sera remplacee par une exception au chapitre 15)
}
double lireNote(std::string_view invite)
{
while (std::cin) {
const std::string ligne = lireLigne(invite);
double note{};
if (!estReelStrict(ligne, note)) {
std::cout << "Saisie invalide : entrez un nombre (ex. 12.5 ou 12,5).\n";
} else if (!estNoteValide(note)) {
std::cout << "La note doit etre comprise entre " << noteMin << " et " << noteMax << ".\n";
} else {
return note;
}
}
return noteMin;
}
} // namespace uin
