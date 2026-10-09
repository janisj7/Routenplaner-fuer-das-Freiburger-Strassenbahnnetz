#include<bits/stdc++.h>
#include <climits>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std ;

//Definieren einer Klasse mit Namen und Stationen, die die Linie befährt
class Straßenbahnlinie {
    public:
        int name;
        vector<string> haltestellen;
        Straßenbahnlinie(int name, vector<string> haltestellen) {
            this -> name = name;
            this->haltestellen = haltestellen;
        }

// Anfangs als Bestandteil des Hauptalgorithmus gedacht, bringt diese Fkt. mir nach der Implementierung von Dijkstra nichts
/*        void ist_Station_auf_Linie(string name, string station) {
            bool gefunden = false;
            for (int i = 0; i < haltestellen.size(); i++) {
                if (haltestellen[i] == station) {
                    cout << "Ja, " << station << " ist auf der Linie " << name << endl;
                    gefunden = true;
                    return;
                }
            }
            cout << "Nein, " << station << " ist nicht auf der Linie " << name << endl;
        }
*/
};
    Straßenbahnlinie linie1(1, {"Landwasser", "Diakoniekrankenhaus", "Moosweiher", "Paduaallee", "Betzenhauser Torplatz", "Am Bischofskreuz", "Runzmattenweg", "Rathaus im Stühlinger", "Eschholzstr.", "Hauptbahnhof", "Stadttheater", "Bertoldsbrunnen", "Oberlinden", "Schwabentorbrücke", "Brauerei Ganter", "Maria-Hilf-Kirche", "Alter Messplatz", "Musikhochschule", "Emil-Gött-Str.", "Hasemannstr.", "Römerhof", "Laßbergstr."});
    Straßenbahnlinie linie2(2, {"Hornusstr.", "Eugen-Martin-Str.","Zollhallenplatz", "Hauptfriedhof", "Friedrich-Ebert-PLatz", "Robert-Koch-Str.", "Rathaus im Stühlinger", "Eschholzstr", "Hauptbahnhof", "Stadttheater", "Bertoldsbrunnen", "Holzmarkt", "Johanneskirche", "Lorettostr.", "Holbeinstr.", "Wonnhalde", "Wiesenweg", "Klosterplatz", "Günterstal"});
    Straßenbahnlinie linie3(3, {"Haid", "VAG-Zentrum", "Am Lindenwäldle", "Bugginger Str.", "Rohrgraben", "Bissierstr.", "Runzmattenweg", "Rathaus im Stühlinger", "Eschholzstr.", "Hauptbahnhof", "Stadttheater", "Bertoldsbrunnen", "Holzmarkt", "Johanneskirche", "Reiterstr.", "Heinrich-von-Stephan-Str.", "Weddigenstr.", "Peter-Thumb-Str.", "Paula-Modersohn-Platz", "Vauban-Mitte", "Vauban"});
    Straßenbahnlinie linie4(4, {"Zähringen", "Glottertalstr.", "Berggasse", "Reutebachgasse", "Tullastr.", "Hornusstr.", "Okenstr.", "Hauptstr.", "Tennenbacher Str.", "Europaplatz", "Bertoldsbrunnen", "Stadttheater", "Hauptbahnhof", "Eschholzstr.", "Rathaus im Stühlinger", "Robert-Koch-Str.", "Killianstr.", "Berliner Allee", "Elsässer Str.", "Technische Fakultät", "Messe"});
    Straßenbahnlinie linie5(5, {"Rieselfeld", "Maria-von-Rudloff-Platz", "Geschwister-Scholl-Platz", "Am Lindenwäldle", "Krozinger Str.", "Dorfbrunnen", "Scherrer-Platz", "Haslach Bad", "Pressehaus", "Heinrich-von-Stephan-Str.", "Matten-str.", "Erbprinzenstr.", "Stadttheater", "Fahnenbergplatz", "Europaplatz"});

// Ich initalisiere alle Linien in einem gesamten Array, um später die Adjazenzmatrix zu erstellen. 
    vector<string> Gesamte_Stationen = {"Landwasser", "Diakoniekrankenhaus", "Moosweiher", "Paduaallee", "Betzenhauser Torplatz", "Am Bischofskreuz", "Runzmattenweg", "Rathaus im Stühlinger", "Eschholzstr.", "Hauptbahnhof", "Stadttheater", "Bertoldsbrunnen", "Oberlinden", "Schwabentorbrücke", "Brauerei Ganter", "Maria-Hilf-Kirche", "Alter Messplatz", "Musikhochschule", "Emil-Gött-Str.", "Hasemannstr.", "Römerhof", "Laßbergstr.", "Hornusstr.", "Eugen-Martin-Str.","Zollhallenplatz", "Hauptfriedhof", "Friedrich-Ebert-PLatz", "Robert-Koch-Str.", "Rathaus im Stühlinger", "Eschholzstr", "Hauptbahnhof", "Stadttheater", "Bertoldsbrunnen", "Holzmarkt", "Johanneskirche", "Lorettostr.", "Holbeinstr.", "Wonnhalde", "Wiesenweg", "Klosterplatz", "Günterstal", "Haid", "VAG-Zentrum", "Am Lindenwäldle", "Bugginger Str.", "Rohrgraben", "Bissierstr.", "Runzmattenweg", "Rathaus im Stühlinger", "Eschholzstr.", "Hauptbahnhof", "Stadttheater", "Bertoldsbrunnen", "Holzmarkt", "Johanneskirche", "Reiterstr.", "Heinrich-von-Stephan-Str.", "Weddigenstr.", "Peter-Thumb-Str.", "Paula-Modersohn-Platz", "Vauban-Mitte", "Vauban", "Zähringen", "Glottertalstr.", "Berggasse", "Reutebachgasse", "Tullastr.", "Hornusstr.", "Okenstr.", "Hauptstr.", "Tennenbacher Str.", "Europaplatz", "Bertoldsbrunnen", "Stadttheater", "Hauptbahnhof", "Eschholzstr.", "Rathaus im Stühlinger", "Robert-Koch-Str.", "Killianstr.", "Berliner Allee", "Elsässer Str.", "Technische Fakultät", "Messe","Rieselfeld", "Maria-von-Rudloff-Platz", "Geschwister-Scholl-Platz", "Am Lindenwäldle", "Krozinger Str.", "Dorfbrunnen", "Scherrer-Platz", "Haslach Bad", "Pressehaus", "Heinrich-von-Stephan-Str.", "Matten-str.", "Erbprinzenstr.", "Stadttheater", "Fahnenbergplatz", "Europaplatz"};

    const int n = 97; //Dopplungen berücksichtigen;
    int cost[n][n];
    void init(){for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cost[i][j] = 9999;
        }
    }
    }



// Funktion, die die Adjazenzmatrix erstellt, also relevant für die Fahrtzeit ist. Es wäre auch mit einer kompakteren for schleife möglich, aber ich wollte es übersichtlich halten.
void Adjazenzmatrix_Straßenbahn(){
    init();

    //Umstieg
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++ ) {
            if (Gesamte_Stationen[i] == Gesamte_Stationen[j]) {
                // Umstiegszeit
                cost[i][j] = 3;
            }
        }
    }


    //Linie 1
    for (int i = 0; i < linie1.haltestellen.size() ; i++) {
        for (int j = 0; j < linie1.haltestellen.size(); j++){

            if ( i == j+1 || i == j-1){
                cost[i][j] = 2;
                cost[j][i] = 2;


            }
        } 
    }
    //Linie 2
    for (int i = linie1.haltestellen.size(); i < linie1.haltestellen.size()+linie2.haltestellen.size(); i++){
        for (int j = linie1.haltestellen.size(); j < linie1.haltestellen.size()+linie2.haltestellen.size(); j++){
            if ( i == j+1 || i == j-1) {
                cost[i][j] = 2;
                cost[j][i] = 2;
            }
        }
    }
    //Linie 3
    for (int i = linie1.haltestellen.size()+linie2.haltestellen.size(); i < linie1.haltestellen.size()+linie2.haltestellen.size()+linie3.haltestellen.size(); i++){
        for (int j = linie1.haltestellen.size()+linie2.haltestellen.size(); j < linie1.haltestellen.size()+linie2.haltestellen.size()+linie3.haltestellen.size(); j++){
            if ( i == j+1 || i == j-1) {
                cost[i][j] = 2;
                cost[j][i] = 2;
            }
        }
    }
    //Linie 4
    for (int i = linie1.haltestellen.size()+linie2.haltestellen.size()+linie3.haltestellen.size(); i < linie1.haltestellen.size()+linie2.haltestellen.size()+linie3.haltestellen.size()+linie4.haltestellen.size(); i++){
        for (int j = linie1.haltestellen.size()+linie2.haltestellen.size()+linie3.haltestellen.size(); j < linie1.haltestellen.size()+linie2.haltestellen.size()+linie3.haltestellen.size()+linie4.haltestellen.size(); j++){
            if ( i == j+1 || i == j-1) {
                cost[i][j] = 2;
                cost[j][i] = 2;
            }
        }
    }
    //Linie 5
    for (int i = linie1.haltestellen.size()+linie2.haltestellen.size()+linie3.haltestellen.size()+linie4.haltestellen.size(); i < linie1.haltestellen.size()+linie2.haltestellen.size()+linie3.haltestellen.size()+linie4.haltestellen.size()+linie5.haltestellen.size(); i++){
        for (int j = linie1.haltestellen.size()+linie2.haltestellen.size()+linie3.haltestellen.size()+linie4.haltestellen.size(); j < linie1.haltestellen.size()+linie2.haltestellen.size()+linie3.haltestellen.size()+linie4.haltestellen.size()+linie5.haltestellen.size(); j++){
            if ( i == j+1 || i == j-1) {
                cost[i][j] = 2;
                cost[j][i] = 2;
            }
        }
    }
}

//Globale Variable für die vom Benutzer eingegebenen Stationen. 
string srcstr, deststr;

// Den Index der Stationen herausfinden

void find(vector<string>& v, vector<int>& a, string& s) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == s) {
            a.push_back(i);
        }
    }
    if (a.size() == 0) {
        cout << "Eine Station wurde leider nicht gefunden, schauen sie die Namen auf der VAG Website nach." << endl;
        exit(0);
    }
}


//Hilfsfunktion für Dijkstra
int get_min(int dist[] , bool visited[]){
    int key = 0 ; 
    int min = INT_MAX ; 
    for(int i=0;i < n ; i++){
        if(!visited[i] && dist[i]<min){
            min = dist[i] ; 
            key = i ; 
        }
    }
    return key ; 
}


// Funktion, die die Terminalausgabe steuert
void Ausgabe(int dist[], int par[], int src, int dest) {
    cout << "von " << Gesamte_Stationen[src] << " zu " << Gesamte_Stationen[dest] << " fahren sie am besten: \n" << endl;
    int temp = dest;
    //Für die reverse Funktion, damit es nicht von rechts nach links ausgibt
    vector<string> Weg;
    while (temp != src) {
        //Damit die Ausgabe schöner ist, hier einen Vector benutzt
        Weg.push_back(Gesamte_Stationen[par[temp]]);
        temp = par[temp];
    }
    reverse(Weg.begin(), Weg.end());
    for (int i = 0; i < Weg.size(); i++) {
        cout << Weg[i] << " -> ";
    }
    cout << Gesamte_Stationen[dest] << endl;
    cout <<"Sie brauchen: " << dist[dest] << " min" << endl;
}

// Implementierung des Dijkstra-Algorithmus
void dijkstra(vector<int> srcvec, vector<int> destvec) {
    //Für Display hier schon definiert:
    int bestsrc;
    int bestdest;
    int bestdist = INT_MAX;
    int bestpar[n];
    int bestdist_array[n];
    int Loesung;
    int src;
    int dest;

// Ich führe den Dijkstra Alg. für jeden einzelnen Wert in den Vektoren aus, um die kürzeste Fahrtzeit zu finden. 
    for(int i = 0; i < srcvec.size(); i++){
        for (int j = 0; j < destvec.size(); j++){
        src = srcvec[i];
        dest = destvec[j];


    bool visited[n] = {0};
    int par[n], dist[n];
    fill(dist, dist + n, INT_MAX);
    //Distanz des Ausgangsknoten wird dauf NUll gesetzt
    dist[src] = 0;
    par[src] = -1;
    //Erkunden des Graphen
    for (int g = 0; g < n - 1; g++) {
        int u = get_min(dist, visited);
        visited[u] = true;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && (dist[u] + cost[u][v]) < dist[v] && cost[u][v] != 9999) {
                par[v] = u;
                dist[v] = dist[u] + cost[u][v];

            }
        }
    }

    // Abgleichen der verschiedene Loesungen, um die beste zu finden. Dies muss wegen den Dopplungen gemacht werden.
    if (dist[dest] < bestdist) {
        bestdist = dist[dest];
        bestsrc = src;
        bestdest = dest;
        for (int k = 0; k < n; k++) {
            bestpar[k] = par[k];
            bestdist_array[k] = dist[k];
        }
        }
        Loesung = dist[dest];
    }
    }
    Ausgabe(bestdist_array, bestpar, bestsrc, bestdest);
}


int main() {  
    
    Adjazenzmatrix_Straßenbahn();
    
    string srcstr, deststr;
    vector<int> srcvec, destvec;
    cout << "\nGib die Anfangsstation ein : ";  
    getline(cin, srcstr);
    
    cout << "\nGib deine gewuenschte Endstation ein : "; 
    getline(cin, deststr);
    
    // srcvec und destvec definieren
    find(Gesamte_Stationen, srcvec, srcstr);
    find(Gesamte_Stationen,destvec,  deststr);

    
    dijkstra(srcvec, destvec);
    return 0;
}    