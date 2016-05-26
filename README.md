#Łakomiak Zofia Anna
##Symulator podboju krain przez Wikingów

Cel symulacji:

Podbicie co najmniej takiej samej ilości krain w danym wieku, co wikingowie (wieki VIII - XI), jeśli nie - przegrana.

Zasady (mniej więcej):

- Wikingowie na starcie mają podbite Norwegię, Szwecję i Danię, tam są ich stałe porty.
- /*Symulacja może nie zakończyć się od razu po przegraniu wikingów z krainą, bo Odyn może kilka razy na wiek ich wskrzesić.*/
- Krainy podbijane są w stałej kolejności - trudność krainy rośnie z wiekiem, w którym są podbijane. 
- Ilość i staty wikingów mierzona w łodziach langskipach (kosztują tyle samo, losowanie spośród: najmniejszych snekkarów, średnich skeidów i drakkarów - mają odpowiednio gorsze i lepsze staty (ale i tak losowe)). Statystyki łodzi przeciw statystykom krainy, dla większej ilości łodzi statystyki sumowane lub uśredniane.
- /*Zabicie wikingów z danej łodzi - usunięcie łodzi.*/ Regeneracja życia podczas powrotu do domu, wówczas dokupienie łodzi za zrabowane łupy, /*prawdopodobieństwo złożenia ofiary dla danego typu łodzi (też wcześniej kupionych) - wtedy podwyższane są jej staty (niewielka wartość), ewentualnie upgrade łodzi do lepszej.*/
//5. punkt i 2. punkt są częściowo głupie, skoro staty są uśredniane. Przegrana w walce oznaczać więc będzie jedno z możliwych zdarzeń: nic(łaska Odyna - wygrana z krainą pomino przegranej w walce)/strata ostatnio zakupionej łodzi/całkowita porażka - każde z P=1/3.
//5. punkt; część dotycząca podwyższenia statystyk danej łodzi i upgrade do lepszej - tego brak w programie
- Bonusowe łupy za szybkie i brutalne pokonanie krainy.
//(+ % zrabowanej kwoty)
