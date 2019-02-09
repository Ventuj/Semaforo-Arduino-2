int r = 7;
int g = 6;
int v = 5;
int r1 = 4;
int g1 = 3;
int v1 = 2;
int drosso;
int dverde;
int dgiallo;
int lampeggi;
void setup() {
  pinMode(r, OUTPUT);
  pinMode(r1, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(g1, OUTPUT);
  pinMode(v, OUTPUT);
  pinMode(v1, OUTPUT);
  Serial.begin(9600);
  Serial.println("Impostazioni semaforo");
  Serial.println("Seleziona quanti lampeggi per il verde");
  while(Serial.available() == 0){}
  lampeggi = serialInput(Serial.readString());
  Serial.print("Hai selezionato: ");
  Serial.print(lampeggi);
  Serial.println("\nSeleziona Durata Rosso in MilliSecondi");
  while(Serial.available() == 0){}
  drosso = serialInput(Serial.readString());
  Serial.print("Hai selezionato: ");
  Serial.print(drosso);
  Serial.println("\nSeleziona Durata Giallo in MilliSecondi");
  while(Serial.available() == 0){}
  dgiallo = serialInput(Serial.readString());
  Serial.print("Hai selezionato: ");
  Serial.print(dgiallo);
  Serial.println("\nSeleziona Itervallo Verde in MilliSecondi");
  while(Serial.available() == 0){}
  dverde = serialInput(Serial.readString());
  Serial.print("Hai selezionato: ");
  Serial.print(dverde);
}
void loop(){
  if(lampeggi != NULL && drosso != NULL && dgiallo != NULL && dverde != NULL){
      esecuzione(r, v1);
      esecuzione(r1, v);
  }
}

int serialInput(String s){
  return s.toInt();
}

void lampeggio(int v){
  for(int i = 0; i < lampeggi; i++){
    digitalWrite(v, HIGH);
    delay(dverde);
    digitalWrite(v,LOW);
    delay(dverde); 
  }
}

void gestgiallo(){
  digitalWrite(g, HIGH);
  digitalWrite(g1, HIGH);
  delay(dgiallo);  
  digitalWrite(g, LOW);
  digitalWrite(g1, LOW);
}

void esecuzione(int rosso, int verde){
  digitalWrite(rosso, HIGH);
  digitalWrite(verde, HIGH);
  delay(drosso);
  lampeggio(verde);
  gestgiallo();
  digitalWrite(rosso,LOW);
}
