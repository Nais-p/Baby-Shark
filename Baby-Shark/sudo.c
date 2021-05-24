#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <crypt.h>
#include <string.h>
#include <shadow.h>
#include <pwd.h>

void tester_setreuid() { //Donner les droit root a l'utilisateur
    uid_t uid_reel;
    uid_t uid_eff;
    uid_reel = getuid();
    uid_eff = geteuid();
    uid_eff, setreuid(uid_eff, -1); 
}

int password () { //Vérifier le password 
    char *motDePasse = getspnam(getenv("USER"))->sp_pwdp; //on récupere le password depuis les variables d'environnement
    char *mot = "";
    mot = getpass("Password: ");
    if (strcmp(crypt(mot, motDePasse), motDePasse) == 0) { //on vérifie si le mdp rentré et le mdp du user sont identique
        return 1;
    }else{
        printf("Mot de passe incorrect !\n");
        return 0;
    }
    return 0;
}


int checkcommand(char *command){ //Vérifier si la command est éxecutable
    if(system(command) != 0 && system(command) != 512){
            system("clear");
            printf("la command n'est pas correcte\n");
            return (1);
        }else if(system(command) == 512) {
            system("clear");
            printf("veuiller compléter la commande\n");
            return (2);
        }else {
            system("clear");
            return (3);
        }
}

char *getcommand(char **command) { //récuperer la commande dans une string
    int size = 0; 
    char *retstr = "";
    for (int i = 0; command[i] != 0; i++) {
        for (int j = 0; command[i][j] != 0; j++) {
            size++;
        }
        size++;
    }
    retstr = malloc(sizeof(char) * size - 1);
    size = 0;
    for (int i = 1; command[i] != 0; i++) {
        for (int j = 0; command[i][j] != 0; j++) {
            retstr[size] = command[i][j];
            size++;
        }
        retstr[size] = ' ';
        size++;
    }
    retstr[size - 1] = 0;
    return retstr;
}

char *getcommand_user(char **command) { //récuperer la command dans une string si l'option --user est appeller
    int size = 0; 
    char *retstr = "";
    for (int i = 0; command[i] != 0; i++) {
        for (int j = 0; command[i][j] != 0; j++) {
            size++;
        }
        size++;
    }
    retstr = malloc(sizeof(char) * size - 1);
    size = 0;
    for (int i = 3; command[i] != 0; i++) {
        for (int j = 0; command[i][j] != 0; j++) {
            retstr[size] = command[i][j];
            size++;
        }
        retstr[size] = ' ';
        size++;
    }
    retstr[size - 1] = 0;
    return retstr;
}

int user_option(int ac, char **av){ //donner les droit du user demander pour l'option --user
    if(ac >= 3){
        if(strcmp(av[1], "--user") == 0){
            char *user = av[2]; // on crée une variable qui va contenir le nouveau user
            char cmd[1000];
            strcpy (cmd, "getent passwd ");
            strcat (cmd, user);
            strcat (cmd, " > /dev/null 2>&1");
            if(!system(cmd)){
                struct passwd *pwd;
                pwd = getpwnam(user); 
                int uid = pwd->pw_uid; // on récupere l'uid du nouveau user 
                uid_t uid_reel;
                uid_t uid_eff;
                uid_reel = getuid();
                uid_eff = geteuid();
                uid_eff, setreuid(uid, uid_reel); // on modifie l'uid du user courant avec le nouveau user
                return 1;
            }else{
                system("clear");
                printf("Utilisateur Inéxistant\n");
                return 2;
            }
        }else {
            return 3;
        }
    }
    return 3;
}


int main(int argc, char *argv[]) {
    if(password() == 1){
        if(user_option(argc, argv) == 1){
            char *command = "";
            command = getcommand_user(argv); //on met la command dans une variable
            if(checkcommand(command) == 3){
                system(command);
                return 0; 
            }
        }else if(user_option(argc, argv) == 3){
            tester_setreuid();
            char *command = "";
            command = getcommand(argv);
            if(checkcommand(command) == 3){
                system(command);
                return 0; 
            }
        }else if(user_option(argc, argv) == 2){
            return 0;
        }
    }
    return 0;
}