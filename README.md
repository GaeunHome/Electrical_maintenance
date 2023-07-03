# 電力維修
<div data-step="14" data-intro="<p>描述中 <i class='fa fa-clipboard'></i> 按鈕可協助你複製到剪貼簿，並貼到本機實驗。</p> <p>若題目有特殊的字元格式，那在範例輸入/輸出測資不適用複製貼上，請務必小心</p>">
<p>一個村莊遭受颱風襲擊。因為所有線路都被吹斷，所有用戶都陷於停電的狀況。</p>
<p>假設電力公司決定<font color="red">根據用戶住家離變電設施的距離，由近到遠做維修</font>。請撰寫一個程式，根據輸入的村莊大小，變電設施以及用戶的位置，<font color="red">輸出電力公司最後維修後的村莊電力狀況</font>。</p>
<h3 class="content-subhead">名詞定義</h3><p><font color="red">附近</font>：以住家為中心，其上、下、左、右兩格範圍，共24格之內。如下圖：</p>
<img src="/img/img1.jpg">
<p>H為某個位置，則上述紅色區域為H的附近。</p>
<h3 class="content-subhead">維修順序說明</h3><p>第一階段先維修變電設施附近的住家。接下來利用所有已經有電的住家為標準，維修其他所有在有電住家附近，但還是停電的住家。依此類推，直到</p>
<ul>
<li>不再有住家停電</li>
<li>不再有任何住家可以用此方式獲得維修服務</li>
</ul>
<p>在圖上會有三種點：</p>
<ul>
<li>0：代表空格</li>
<li>2：代表變電所。村莊內只有一個變電所。</li>
<li>1：代表有電的住家  </li>
<li>9：代表停電的住家</li>
</ul>
<p>輸入格式：</p>
<ul>
<li>第一行是兩個整數N,M。代表村莊大小範圍。N和M都不會超過10</li>
<li>第二行是兩個整數a,b，代表變電所在村莊內的位置。</li>
<li>第三行以下有最多Z行，每行兩個數值。代表村莊內所有住家位置。Z小於等於50。</li>
</ul>
<p>輸出格式：N+1行</p>
<ul>
<li>第一行是有多少房子尚未恢復供電。</li>
<li>接下來N行，每行M個數字。代表維修後狀況。兩兩數字之間有一個空格，但最後一個數字後面不可以有空格。</li>
</ul>
<h3 class="content-subhead">Hint</h3><p>不知如何完成此作業者可參考以下作法：</p>
<ul>
<li>反覆掃過整個地圖。只要碰到還沒有維修好的房子，就檢查它附近是否有變電所或是已經有電的房子。如果有，就將此房子設為有電。</li>
<li>上述步驟在所有房子都已經有電，或是在掃過整個地圖後找不到任何房子可以被修復的話就結束程式。</li>
</ul>
<p>上述方式，主迴圈虛擬碼(pseudo code)如下：</p>
<pre><code><span class="fw-code-copy-button pure-button"><i class="fa fa-clipboard"></i></span><div id="highlighter_987529" class="syntaxhighlighter nogutter  "><table border="0" cellpadding="0" cellspacing="0"><tbody><tr><td class="code"><div class="container"><div class="line number1 index0 alt2"><code class="keyword bold">while</code> <code class="plain">there is any power-failure house f</code></div><div class="line number2 index1 alt1"><code class="plain">{</code></div><div class="line number3 index2 alt2"><code class="undefined spaces">&nbsp;&nbsp;</code><code class="plain">findHousetoRepair &lt;- </code><code class="keyword bold">false</code></div><div class="line number4 index3 alt1"><code class="undefined spaces">&nbsp;&nbsp;</code><code class="keyword bold">for</code> <code class="plain">each cell c in the map</code></div><div class="line number5 index4 alt2"><code class="undefined spaces">&nbsp;&nbsp;</code><code class="plain">{</code></div><div class="line number6 index5 alt1"><code class="undefined spaces">&nbsp;&nbsp;&nbsp;&nbsp;</code><code class="keyword bold">if</code> <code class="plain">c is a power-failure house</code></div><div class="line number7 index6 alt2"><code class="undefined spaces">&nbsp;&nbsp;&nbsp;&nbsp;</code><code class="plain">{</code></div><div class="line number8 index7 alt1"><code class="undefined spaces">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</code><code class="keyword bold">if</code> <code class="plain">there is any substaion or house that the power is back on in the vicinity</code></div><div class="line number9 index8 alt2"><code class="undefined spaces">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</code><code class="plain">{</code></div><div class="line number10 index9 alt1"><code class="undefined spaces">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</code><code class="plain">f &lt;- power is back on</code></div><div class="line number11 index10 alt2"><code class="undefined spaces">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</code><code class="plain">findHousetoRepair &lt;- </code><code class="keyword bold">true</code></div><div class="line number12 index11 alt1"><code class="undefined spaces">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</code><code class="plain">}</code></div><div class="line number13 index12 alt2"><code class="undefined spaces">&nbsp;&nbsp;&nbsp;&nbsp;</code><code class="plain">}</code></div><div class="line number14 index13 alt1"><code class="undefined spaces">&nbsp;&nbsp;</code><code class="plain">}</code></div><div class="line number15 index14 alt2"><code class="undefined spaces">&nbsp;&nbsp;</code><code class="keyword bold">if</code> <code class="plain">findHousetoRepair is </code><code class="keyword bold">false</code></div><div class="line number16 index15 alt1"><code class="undefined spaces">&nbsp;&nbsp;</code><code class="plain">{</code></div><div class="line number17 index16 alt2"><code class="undefined spaces">&nbsp;&nbsp;&nbsp;&nbsp;</code><code class="plain">end the </code><code class="keyword bold">while</code> <code class="plain">loop</code></div><div class="line number18 index17 alt1"><code class="undefined spaces">&nbsp;&nbsp;</code><code class="plain">}</code></div><div class="line number19 index18 alt2"><code class="plain">}</code></div></div></td></tr></tbody></table></div>
</code></pre>
<h3 class="content-subhead">Input Example 1</h3><p>假設村莊大小7x7，變電所位於(2,2)。村莊內有2個住家，位置(3,4)，(4,5)。則初始地圖是：</p>
<img src="/img/img2.jpg">

<p>上例輸入是：</p>
<pre><code><span class="fw-code-copy-button pure-button"><i class="fa fa-clipboard"></i></span><div id="highlighter_811999" class="syntaxhighlighter nogutter  "><table border="0" cellpadding="0" cellspacing="0"><tbody><tr><td class="code"><div class="container"><div class="line number1 index0 alt2"><code class="plain">7 7</code></div><div class="line number2 index1 alt1"><code class="plain">2 2</code></div><div class="line number3 index2 alt2"><code class="plain">3 4</code></div><div class="line number4 index3 alt1"><code class="plain">4 5</code></div></div></td></tr></tbody></table></div>
</code></pre>
<h3 class="content-subhead">Output Example 1</h3><p>上面輸入中，(3,4)的住家位於變電所附近，且(4,5)在(3,4)附近。因此所有房子最後都會恢復供電。維修完畢後的地圖是：</p>
<img src="/img/img4.jpg">

<p>輸出為：</p>
<pre><code><span class="fw-code-copy-button pure-button"><i class="fa fa-clipboard"></i></span><div id="highlighter_200055" class="syntaxhighlighter nogutter  "><table border="0" cellpadding="0" cellspacing="0"><tbody><tr><td class="code"><div class="container"><div class="line number1 index0 alt2"><code class="plain">0</code></div><div class="line number2 index1 alt1"><code class="plain">0 0 0 0 0 0 0</code></div><div class="line number3 index2 alt2"><code class="plain">0 0 0 0 0 0 0</code></div><div class="line number4 index3 alt1"><code class="plain">0 0 2 0 0 0 0</code></div><div class="line number5 index4 alt2"><code class="plain">0 0 0 0 1 0 0</code></div><div class="line number6 index5 alt1"><code class="plain">0 0 0 0 0 1 0</code></div><div class="line number7 index6 alt2"><code class="plain">0 0 0 0 0 0 0</code></div><div class="line number8 index7 alt1"><code class="plain">0 0 0 0 0 0 0</code></div></div></td></tr></tbody></table></div>
</code></pre>
<h3 class="content-subhead">Input Example 2</h3><p>假設村莊大小6x8，變電所位於(0,1)。村莊內有4個住家，位置(0,2)，(2,2)，(3,7)，(1,5)。則初始地圖是：</p>
<img src="/img/img44.jpg">
<p>輸入為：</p>
<pre><code><span class="fw-code-copy-button pure-button"><i class="fa fa-clipboard"></i></span><div id="highlighter_646444" class="syntaxhighlighter nogutter  "><table border="0" cellpadding="0" cellspacing="0"><tbody><tr><td class="code"><div class="container"><div class="line number1 index0 alt2"><code class="plain">6 8</code></div><div class="line number2 index1 alt1"><code class="plain">0 0</code></div><div class="line number3 index2 alt2"><code class="plain">1 1</code></div><div class="line number4 index3 alt1"><code class="plain">3 2</code></div><div class="line number5 index4 alt2"><code class="plain">3 7</code></div><div class="line number6 index5 alt1"><code class="plain">1 5</code></div></div></td></tr></tbody></table></div></code></pre>
<h3 class="content-subhead">Output Example 2</h3><p>上面輸入中，只有(1,1)和(3,2)的住家位於變電所附近，或是因為附近有維修完畢的住家而在維修範圍內。位置(3,7)和(1,5)的住家不在維修範圍內。輸出是：</p>
<pre><code><span class="fw-code-copy-button pure-button"><i class="fa fa-clipboard"></i></span><div id="highlighter_929169" class="syntaxhighlighter nogutter  "><table border="0" cellpadding="0" cellspacing="0"><tbody><tr><td class="code"><div class="container"><div class="line number1 index0 alt2"><code class="plain">2</code></div><div class="line number2 index1 alt1"><code class="plain">2 0 0 0 0 0 0 0</code></div><div class="line number3 index2 alt2"><code class="plain">0 1 0 0 0 9 0 0</code></div><div class="line number4 index3 alt1"><code class="plain">0 0 0 0 0 0 0 0</code></div><div class="line number5 index4 alt2"><code class="plain">0 0 1 0 0 0 0 9</code></div><div class="line number6 index5 alt1"><code class="plain">0 0 0 0 0 0 0 0</code></div><div class="line number7 index6 alt2"><code class="plain">0 0 0 0 0 0 0 0</code></div></div></td></tr></tbody></table></div></code></pre></div>
