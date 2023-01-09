# Model animowany do gry

Gratulacje! Dziś pierwszy dzień w Twojej Nowej Pracy. Twoim zadaniem jest wsparcie teamu programistów, którzy będą tworzyli grę na bazie Twojego modelu fizycznego. Założenie projektu jest proste – macie stworzyć dowolną grę komputerową, której mechanika jest oparta o model fizyczny. Po pierwszej burzy mózgów wybór padł na model masy zawieszonej na sprężynkach. Wybór jest oczywisty – model jest prosty, można go zaimplementować dość szybko. Istnieją materiały w sieci, gdzie jest to ogólnie wytłumaczone w kontekście problemu całkowania równań ruchu Newtona, na przykład tu https://youtu.be/wFzkhmsFp_E lub tu https://youtu.be/Xix6N4CgCrY

Twoje zadanie polega na opracowaniu modelu mechaniki gry oraz wstępnej implementacji. Pamiętaj – nie masz napisać gry. Nie masz też dostarczyć efektownej wizualzacji 3D, ani super dopracowanego kodu. Masz za to opracować animowany model (postać, obiekt, mechanizm itp.) oparty o cząsteczki zawieszone na sprężynkach. Użytkownik powinien mieć możliwość wejścia w interakcję z modelem (np. wykonać jakąś akcję – rzut, pociągnięcie, przesuniecie, przestawienie, modyfikacja modelu etc.), która powinna dać efekt nagrody lub kary. Opracowanie modelu wiąże się też ze wstępną implementacją, czyli musi być możliwość, aby menadżer projektu pobawił się modelem i stwierdził, czy ten się nadaje do dalszego opracowania przez team programistów.

Przykładowe modele: łuk z naciąganą cięciwą (naciągnięcie pozwala wypuścić strzałę, od użytkownika zależy precyzja strzału), kamień zawieszony na linie (rotacja, puszczenie kamienia który leci odpowiednio daleko), model kroczących postaci z możliwością skoku lub ruchu (ruch przez modyfikację siły mięści – współczynnika sprężystości wybranych sprężyn), membrana / lina z odbijanymi obiektami (model rakiety tenisowej, sprężyste odbicia od siatki), skoki bungee, przeciąganie liny (zostawiam Tobe szczegóły), model mostu i jego wytrzymałość (były kiedyś takie gry, bridge construction itp.), model uderzenia piłki zbudowanej ciała miękkiego i wiele wiele innych. Menadżer projektu w firmie na pewno doceni projekty wykraczające poza ww. opis.

## Minimalne wymagania:

1. Implementacja oparta o metodę Verleta
2. Model jednowymiarowy liny lub dwu i trójwymiarowy
3. Uwzględnienie sił zewnętrznych spoza zbioru {grawitacja, sprężystość, siła oporu}
4. Oryginalność i złożoność modelu
5. Grywalność i przyjemność płynąca z mechaniki i tworzonej animacji