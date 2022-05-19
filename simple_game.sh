#!/bin/bash

min=$1
max=$2
iterator=1
number_to_guess=$(( ( RANDOM % $max )+$min ))

while [ true ]
do
	if (( $iterator <= 10 ))
	then
		echo "Zgadnij liczbę: "
		read user_number
		if (( $user_number == $number_to_guess ))
		then
			echo "Brawo, odgadłeś(-aś) liczbę!"
			break
		elif (( $user_number < $number_to_guess ))
		then
			echo "Wprowadzona liczba jest za mała"
		else
			echo "Wprowadzona liczba jest za duża"
		fi
		if (( 10-$iterator>0 ))
		then
			echo "Pozostało Ci jeszcze $(( 10-iterator)) prób!"
		else
			echo "Przegrałeś, ale by zagrać jeszcze raz, uruchom ponownie skrypt. Może tym razem fortuna uśmiechnie się do Ciebie :)"
			break
		fi
	fi
	iterator=$(( iterator+1 ))
done

