max=10000;
echo "Entrez la vitesse que vous shouaitez :\n";
for ((i = 0; i < $max; i++))
do
	clear;
	./a.out $i;
	sleep 0.042;
done
