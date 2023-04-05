# Shift Or Algoritması

### Uygulamanın Amacı

Uygulamada bir metin dosyasından seçilen kelimelerin kaç kez geçtiği hesaplanmaktadır.

---

### Uygulama Hakkında

Uygulama konsolda çalıştırılıp c programlama dili kullanılmıştır. `alice_in_wonderland.txt` dosyası `shiftORAlgoritmasi.c` dosyasında `fopen` fonksiyonuyla açılıp okunmuş ve bu dosyadaki "upon,sigh,Dormouse,jury-box,swim" kelimelerinin kaç kez geçtiği shift OR algoritması kullanılarak hesaplanmıştır. Ancak shift OR algoritması ilk eşleşmeyi ve bulunduğu
dizini döndürdüğünden findAllPatterns fonksiyonu içinde çağrılmış ve tüm eşleşme sayısını döndürmesi için gerekli işlemler findAllPatterns fonksiyonunda yapılmıştır.

---

### Uygulamayı Çalıştırmak İçin

1. Repodaki shiftORAlgoritmasi.c ve alice_in_wonderland.txt dosyalarını indirin. Ve masaüstünüzde bir klasör oluşturun. Oluşturduğunuz klasöre hepsini taşıyın.
2. Bilgisayarınızda c dosyasının çalışabilmesi için IDE kurulu olması gerekmektedir. Yüklü değilse indirmek için aşağıdaki IDE'lerden yararlanabilirsiniz:
   <br>Code::Blocks, Dev-C++, Eclipse, NetBeans(gerekli eklentiler yükleyerek kullanılabilir) ve Visual Studio Code(gerekli eklentiler yükleyerek kullanılabilir)
3. Klasörünüzdeki shiftORAlgoritmasi.c dosyasını yüklediğiniz IDE'de çalıştırın.

---

### Algoritmanın Amacı ve Kullanım Alanları

Shift-OR algoritması, bir metinde belirli bir desenin varlığını tespit etmek için kullanılan bir dize eşleme algoritmasıdır. Bu desen, bir anahtar kelime, bir kelime öbeği veya herhangi bir metin parçası olabilir.

Shift-OR algoritması, desenin bit seviyesinde işlenmesi için tasarlanmıştır. Desenin her bir karakteri için bir bit vektörü oluşturulur ve bu vektörler bir araya getirilerek desenin tamamını temsil eden bir bit vektörü elde edilir. Metin parçası da bit seviyesinde işlenir ve desenin varlığı, metnin bit vektörü üzerinde yapılacak kaydırmalar ve bit işlemleri ile tespit edilir.

Özellikle büyük metinlerde desen arama işlemlerini hızlandırmak için kullanılır. Kullanım alanları arasında dosya veya veri sıkıştırma, veri sıkıştırma, biyoenformatik, web sayfası tarama ve arama motorları gibi çeşitli alanlar bulunmaktadır.

---

### Algoritmanın Çalışma Şekli

1. Desenin Bit Vektörünü Oluşturma:

   - Desenin her bir karakteri için bir bit vektörü oluşturulur.
   - Her karakterin bit vektörü, desenin tamamını temsil eden bir bit vektörü oluşturmak için bir araya getirilir.
     Örneğin, "ABCD" deseni için bit vektörleri şu şekilde olabilir: A: 0001, B: 0010, C: 0100, D: 1000 ve desenin bit vektörü: 1111.

2. Metin Parçasının Bit Vektörünü Oluşturma:

   - Metin parçası da bit seviyesinde işlenir ve metnin bit vektörü oluşturulur.
   - Metin parçası bit bit işlenir ve her karakterin bit vektörü desenin bit vektörü ile karşılaştırılır.
   - Eğer karakterin bit vektörü desenin bit vektörüyle eşleşirse, bu karakterin biti metnin bit vektöründe "1" olarak işaretlenir. Aksi takdirde "0" olarak işaretlenir.
   - Bit vektörleri, metnin tamamında işlenene kadar bu işlem tekrarlanır.

3. Bit Vektörleri Karşılaştırma:

   - Desenin bit vektörü ve metnin bit vektörü karşılaştırılır.
   - Bit vektörlerindeki eşleşen bitlerin sayısı sayılır.
   - Eğer eşleşen bitlerin sayısı, desenin uzunluğuna eşitse, desenin varlığı tespit edilir.

4. Kaydırma İşlemi:

   - Eğer desenin varlığı tespit edilmezse, metnin bit vektörü belirli bir sayıda bit kaydırılır ve işlem tekrar edilir.
     Bu sayede, metindeki tüm olası konumlarda desen aranabilir.
   - Kaydırma işlemi, desenin uzunluğuna eşit sayıda bit kaydırılana kadar tekrarlanır.

5. İşlem Sonlandırma:

   - Desenin varlığı tespit edildiğinde, işlem sonlandırılır ve desenin konumu veya sayısı rapor edilir.

---

### Algoritmanın Çalışma Zamanı Analizi

<br>

#### En İyi Durum:

Shift-OR algoritmasının çalışma zamanı, desenin uzunluğu olan m'ye ve metnin uzunluğu olan n'ye 
bağlıdır. Çalışma zamanı analizi, bit vektörleri ve bit işlemleri değerlendirilerek yapılır. 
Desen metnin başında bulunur ve tek bir kaydırma işlemi ile tespit edilir. Bu durumda, algoritmanın 
çalışma zamanı O(m) olur, burada m desenin uzunluğudur.

#### En Kötü Durum:

Metnin uzunluğu n ve desenin uzunluğu m olmak üzere, desen metnin sonunda bulunur ve metnin tamamı kaydırılır.
Bit vektöründe m adet bit pozisyonu olduğunu ve her karakter pozisyonunda bir OR işlemi gerçekleştirildiği göz önüne alınır. Desenin her bir karakteri için bu işlem tekrarlandığından toplamda n\*m bit işlemi gerçekleştirilir. Çalışma zamanı O(nm) olur.

#### Ortalama Durum:

Ortalama durumda, Shift-OR algoritması genellikle metnin orta kısmında deseni bulur ve  her 
bir karakter karşılaştırması için sabit zaman harcar. Bu nedenle algoritmanın çalışma süresi 
n ve m'ye bağlı olarak O(n+m) zaman karmaşıklığına sahip olur.
