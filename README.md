# RoomKeyChecker

Arduino YunとIFTTT( https://ifttt.com/recipes )を用いて鍵の状態をチェックし、各種のメディアに反映します。
私はtwitterにつぶやかせてます。ソースコード上のoooの部分にはEvent Nameを、xxxの部分はKeyを入れます。

傾きセンサをドアの内側（=室内側）の鍵の部分にくくって傾きを取ることを想定しています。
鍵が締まればセンサは傾き（=HIGH）、開けばセンサは垂直になる(=LOW)作りです。
