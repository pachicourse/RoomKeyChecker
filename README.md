# RoomKeyChecker

Arduino YunとIFTTT( https://ifttt.com/recipes )を用いて鍵の状態をチェックし、各種のメディアに反映します。
私はtwitterにつぶやかせてます。curlコマンドのoooの部分にはEvent Nameを、xxxの部分はKeyを入れます。

傾きセンサをドアの内側（=室内側）の鍵の部分にくくって傾きを取ることを想定しています。
鍵が閉まればセンサは傾き（=HIGH）、開けばセンサは垂直になる(=LOW)作りです。単純明快。

サークルの部室の鍵が開いてるかどうか知りたかったのでやっつけでやりました。
