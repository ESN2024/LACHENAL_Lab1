# LACHENAL_Lab1 : "Let there be light"

## Introduction

L'objectif de ce TP est de mettre en pratique le cours de conception conjointe. Ici le but est de créer un chenillard avec un FPGA Altera MAX 10 10M50DAF484C7G et de la carte DE10 Lite. Le cahier des charges nous précise que le chenillard est composé de 8 LEDs, il doit être activé avec un bouton et l'on peut modifier la vitesse avec 4 switchs.


## Architecture du systeme

Pour respecter le cahier des charges, l'architecture du systeme est développé sur Qsys avec les composants suivants : 

    - Un processeur NIOS II
    - Un JTAG UART (affichage sur le terminal)
    - Memoire (taille = 40000 octets)
    - PIO_0 de 8 bits en sortie pour les LEDs
    - PIO_1 de 1 bit en entré pour le bouton poussoir (active le chenillard)
    - PIO_2 de 4 bits en entrés pour les switchs (modifie la vitesse de clignotement des LEDs)

Vitesse par défault 2 secondes par LEDs
SW0 à 1 = 1s;
SW1 à 1 = 0.8s;
SW2 à 1 = 0.4s;
SW3 à 1 = 0.2s;

Quand on reste appuyer sur le bouton, une interruption est produite pour activer le chenillard.

## Conclusion

Ce TP m'a permis de comprendre la base du codesign et l'interêt des interruptions dans un système.
