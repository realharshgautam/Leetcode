<h2><a href="https://leetcode.com/problems/kth-distinct-string-in-an-array">Kth Distinct String in an Array</a></h2> <img src='https://img.shields.io/badge/Difficulty-Easy-brightgreen' alt='Difficulty: Easy' /><hr><p>A <strong>distinct string</strong> is a string that is present only <strong>once</strong> in an array.</p>

<p>Given an array of strings <code>arr</code>, and an integer <code>k</code>, return <em>the </em><code>k<sup>th</sup></code><em> <strong>distinct string</strong> present in </em><code>arr</code>. If there are <strong>fewer</strong> than <code>k</code> distinct strings, return <em>an <strong>empty string </strong></em><code>&quot;&quot;</code>.</p>

<p>Note that the strings are considered in the <strong>order in which they appear</strong> in the array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> arr = [&quot;d&quot;,&quot;b&quot;,&quot;c&quot;,&quot;b&quot;,&quot;c&quot;,&quot;a&quot;], k = 2
<strong>Output:</strong> &quot;a&quot;
<strong>Explanation:</strong>
The only distinct strings in arr are &quot;d&quot; and &quot;a&quot;.
&quot;d&quot; appears 1<sup>st</sup>, so it is the 1<sup>st</sup> distinct string.
&quot;a&quot; appears 2<sup>nd</sup>, so it is the 2<sup>nd</sup> distinct string.
Since k == 2, &quot;a&quot; is returned. 
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> arr = [&quot;aaa&quot;,&quot;aa&quot;,&quot;a&quot;], k = 1
<strong>Output:</strong> &quot;aaa&quot;
<strong>Explanation:</strong>
All strings in arr are distinct, so the 1<sup>st</sup> string &quot;aaa&quot; is returned.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> arr = [&quot;a&quot;,&quot;b&quot;,&quot;a&quot;], k = 3
<strong>Output:</strong> &quot;&quot;
<strong>Explanation:</strong>
The only distinct string is &quot;b&quot;. Since there are fewer than 3 distinct strings, we return an empty string &quot;&quot;.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= arr.length &lt;= 1000</code></li>
	<li><code>1 &lt;= arr[i].length &lt;= 5</code></li>
	<li><code>arr[i]</code> consists of lowercase English letters.</li>
</ul>
