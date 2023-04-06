Om het lovelace menu volledig te benutten dient via hacs (frontend)
de volgende repositories geinstalleerd te worden (verkennen en downloaden)

stack-in-card
multiple-entity-row
bar-card
apexcharts  (staafdiagram)

automations.yaml samenvoegen  met de bestaande automations.yaml
clack.yaml samenvoegen met configuration.yaml 

of op een eigen lokatie zetten:
configuration.yaml aanpassen naar:

homeassistant:
  packages: !include_dir_named packages

Dan directory /packages aanmaken in /config en daar de clack.yaml in kopieren
HA opnieuw starten
In clack.yaml moeten de tijden nog aangepast worden aan je eigen tijden (timer) voor de simulatie van het regenereren in HA.
Even met een stopwatch ofzo, nadat de regeneratie handmatig gestart is. Elke keer dat de inwendige schuif beweegt is een stap (zie ook het display vd clack)

Bijgevoegd ook de plaatjes voor de simulatie van het zoutniveau:
naar /www/images kopieren


De werking van de 2 relays moeten nog in de clack ingesteld worden:
Relay 1 is voor de waterpulsen te tellen tijdens normale werking
Relay 2 is voor eenmalig een puls te geven wanneer de ontharder regenereerd
Achter op de print staat welk draadje voor wat is om aan de relays aan te sluiten (de 3 aderige stekkerblok)

Instellen:  (zie ook word document)
next + pijltje omlaag -> 5 sec vasthouden
next (softening) is dan zichtbaar
doordrukken op next tot <rlY 1>  Deze op ON zetten (softening  L)
next
Dan op 2 L zetten  (elke flowmeter puls is dan 2 ltr)
next
set time: 0.01 min
next
set  rlY 2 "time" to on  (geeft dan een puls bij regeneratie start)
next
set time: 0.01 min
2x next en klaar

Succes!

Het monteren van de esp print in de behuizing is wel wat lastig.
De ESP print steekt achter de rand naar binnen, van de clack behuizing zodat deze weer gesloten kan worden met de kap.
Soms wil het esp printje uit de pinnen komen. (iets of wat speling mag wel)



