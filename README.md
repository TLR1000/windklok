# windklok
Display windsnelheid Haringvliet

De windklok bestaat uit 3 componenten:
-Scraper
-API
-Display

Scraper
Dit is een Google apps script dat de windsnelheid ophaalt en wegschrijft in een Google doc.
Het script draait iedere 10 minuten. 

API
Een JSON Rest API die de gevraagde windsnelheid in knopen teruggeeft.
De API gebruikt het Google doc als databron.
De ApI is gedeployed in een Google cloud omgeving.

Display
Core van de Display is een Arduino die alleen logica bevat voor het tonen van de windsnelheid.
De display roept met regelmatige intervallen de API aan en bestuurt de uitvoer.
Display stuurt oa. een servo aan voor de wijzer, een display, evt. een pir, donker/licht modus, etc.
