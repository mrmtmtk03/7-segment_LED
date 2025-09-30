# 7セグメントLED回路
## 回路構成
KiCadにて回路図を作成した。
7セグメントデコーダー([TC4511BP](https://toshiba.semicon-storage.com/jp/semiconductor/product/general-purpose-logic-ics/detail.TC4511BP.html))を使用して、4つの7セグメントLEDをArduino UNOによりダイナミック点灯する回路である。
![KiCadにて作成した回路図](/images/circuit01.png)
## 使用部品
使用する7セグメントLEDはカソードコモンで、データシートより順方向電圧$`V_F=3.5\,[\mathrm{V}]`$、順方向電流の絶対最大定格は$`I_F=35\,[\mathrm{mA}]`$である。
今回は$`I_F=4.5\,[\mathrm{mA}]`$となるように抵抗1を選定し以下のようにRを330 Ωと定める。
```math
R_1=\frac{V-V_F}{I_F}=\frac{5-3.5}{0.0045}≒330\,[\mathrm{Ω}]
```
具体的な使用部品は以下の表に示す。
|部品|型番|秋月電子販売コード|
|:--|:--|:--:|
|7セグメントドライバー|TC4511BP|[114057](https://akizukidenshi.com/catalog/g/g114057/)|
|7セグメントLED|OSL10391-LRA|[130319](https://akizukidenshi.com/catalog/g/g130319/)|
|抵抗器|330 Ω|[107812](https://akizukidenshi.com/catalog/g/g107812/)|
|丸ピンICソケット(16P)|2227MC-16-03|[100029](https://akizukidenshi.com/catalog/g/g100029/)|
|細ピンヘッダー(オスL型) 1×12|PHA-1x12RG|[111573](https://akizukidenshi.com/catalog/g/g111573/)|

なお、点灯させるためには、この他に[Arduino UNO](https://akizukidenshi.com/catalog/g/g115574/)が必要である。
