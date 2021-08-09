Fonctionnement de la coopération entre 2 tâches : 

    - tâche 1 : led on toutes les 500 ms
    - tâche 2 : led off toutes les 1000 ms

Sans coopération : 

500 ms : la led s'allume
1000 ms : la led s'éteind et se rallume (ou l'inverse)
1500 ms : la led s'allume 
2000 ms : la led s'éteind et se rallume (ou l'inverse)

Avec coopération : 

500 ms : la led s'allume si elle s'est éteinte il y a bien 1000 ms
1000 ms : la led s'éteind si elle s'est bien allumée il y a 500 ms et elle