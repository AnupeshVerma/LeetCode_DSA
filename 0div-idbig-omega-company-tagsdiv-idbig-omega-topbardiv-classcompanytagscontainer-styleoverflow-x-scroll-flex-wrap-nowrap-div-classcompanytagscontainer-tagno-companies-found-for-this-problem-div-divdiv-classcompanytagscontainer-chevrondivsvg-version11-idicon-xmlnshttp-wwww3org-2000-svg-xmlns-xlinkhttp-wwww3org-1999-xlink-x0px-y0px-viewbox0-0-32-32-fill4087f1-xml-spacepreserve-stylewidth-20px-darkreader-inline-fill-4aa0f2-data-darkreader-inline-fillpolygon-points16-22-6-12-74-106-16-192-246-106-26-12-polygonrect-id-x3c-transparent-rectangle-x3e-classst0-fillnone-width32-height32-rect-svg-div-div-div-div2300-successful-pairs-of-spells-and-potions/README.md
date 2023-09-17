<h2><a href="https://leetcode.com/problems/successful-pairs-of-spells-and-potions/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px; --darkreader-inline-fill: #4aa0f2;" data-darkreader-inline-fill=""><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>2300. Successful Pairs of Spells and Potions</a></h2><h3>Medium</h3><hr><div><p>You are given two positive integer arrays <code>spells</code> and <code>potions</code>, of length <code>n</code> and <code>m</code> respectively, where <code>spells[i]</code> represents the strength of the <code>i<sup>th</sup></code> spell and <code>potions[j]</code> represents the strength of the <code>j<sup>th</sup></code> potion.</p>

<p>You are also given an integer <code>success</code>. A spell and potion pair is considered <strong>successful</strong> if the <strong>product</strong> of their strengths is <strong>at least</strong> <code>success</code>.</p>

<p>Return <em>an integer array </em><code>pairs</code><em> of length </em><code>n</code><em> where </em><code>pairs[i]</code><em> is the number of <strong>potions</strong> that will form a successful pair with the </em><code>i<sup>th</sup></code><em> spell.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> spells = [5,1,3], potions = [1,2,3,4,5], success = 7
<strong>Output:</strong> [4,0,3]
<strong>Explanation:</strong>
- 0<sup>th</sup> spell: 5 * [1,2,3,4,5] = [5,<u><strong>10</strong></u>,<u><strong>15</strong></u>,<u><strong>20</strong></u>,<u><strong>25</strong></u>]. 4 pairs are successful.
- 1<sup>st</sup> spell: 1 * [1,2,3,4,5] = [1,2,3,4,5]. 0 pairs are successful.
- 2<sup>nd</sup> spell: 3 * [1,2,3,4,5] = [3,6,<u><strong>9</strong></u>,<u><strong>12</strong></u>,<u><strong>15</strong></u>]. 3 pairs are successful.
Thus, [4,0,3] is returned.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> spells = [3,1,2], potions = [8,5,8], success = 16
<strong>Output:</strong> [2,0,2]
<strong>Explanation:</strong>
- 0<sup>th</sup> spell: 3 * [8,5,8] = [<u><strong>24</strong></u>,15,<u><strong>24</strong></u>]. 2 pairs are successful.
- 1<sup>st</sup> spell: 1 * [8,5,8] = [8,5,8]. 0 pairs are successful. 
- 2<sup>nd</sup> spell: 2 * [8,5,8] = [<strong><u>16</u></strong>,10,<u><strong>16</strong></u>]. 2 pairs are successful. 
Thus, [2,0,2] is returned.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == spells.length</code></li>
	<li><code>m == potions.length</code></li>
	<li><code>1 &lt;= n, m &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= spells[i], potions[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= success &lt;= 10<sup>10</sup></code></li>
</ul>
</div>