long lastms;//Váriavel para guardar o ultimo toque.

void setup()
{
    Serial.begin(9600);//Inicia a comunicação Serial para visualização dos valores do Touch.
    pinMode(LED_BUILTIN, OUTPUT);//Define o LED OnBoard como saída
    touchAttachInterrupt(4, led, 20);//Atribui uma função (led) quando for detectado um valor menor de (20) ao pino (4).
    lastms = 0;//Inicializa a váriavel em 0.

    //Para chegar a este valor usado (20), é necessário apenas ver os valores que aparece no Serial monitor,
    //toque o fio e veja qual sera o novo valor. Ao tocar, a tendencia do valor é aproximar-se de 0.
}


void loop()
{
    Serial.println(touchRead(4));//Mostra o valor do touch no monitor.
    delay(100);
}

void led()//função que foi atribuida para o evento do touch.
{
    if (millis() - lastms > 150)//Verifica se o ultimo toque faz mais de 150mS
    {
        digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));//Inverte o estado do led.
        lastms = millis();//Salva o ultimo tempo em que foi tocado.
    }
}
