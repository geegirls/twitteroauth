<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
  <head>
    <title>Twitter OAuth in PHP</title>
    <meta http-equiv="Content-Type" content="text/html;charset=utf-8" />
    <style type="text/css">
      img {border-width: 0}
      * {font-family:'Lucida Grande', sans-serif;}
    </style>
  </head>
  <body>
    <div>
      <h2>Welcome to a Twitter OAuth PHP example.</h2>

      <p>This site is a basic showcase of Twitters OAuth authentication method. If you are having issues try <a href='./clearsessions.php'>clearing your session</a>.</p>

      <p>
        Base On:
        <a href='http://github.com/abraham/twitteroauth'>Source Code</a> &amp;
        Contact @<a href='http://twitter.com/abraham'>abraham</a>
      </p>
	  <p>added working example  
		 <a href="token.php">manual token</a> &
		 <a href="search.php">sample search implementation</a>
	  </p>
      <hr />
      <?php if (isset($menu)) { ?>
        <?php echo $menu; ?>
      <?php } ?>
    </div>
    <?php if (isset($status_text)) { ?>
      <?php echo '<h3>'.$status_text.'</h3>'; ?>
    <?php } ?>
    <p>
      <pre>
        <?php print_r($content); ?>
      </pre>
    </p>
	<p>
	<?php if (isset($denget)) { ?>
    
	your id = <?php echo $denget->id; ?><br/>
	your name = <?php echo $denget->name; ?><br/>
	

	<?php 
	echo '<pre>';
	//print_r($denget->id); 
	//echo 'id = '.$denget->id; 
	$result = json_encode($denget);
	//$result = json_decode($denget,true);
	//echo $result; 
	//echo $denget[115806808]['name'];
	//foreach ($denget as $get):
	//	print_r( $get);
	//endforeach;
	//echo $denget;
	
	
	//get key and value from array
	$jsonIterator = new RecursiveIteratorIterator(
    new RecursiveArrayIterator(json_decode($result, TRUE)),
    RecursiveIteratorIterator::SELF_FIRST);

		foreach ($jsonIterator as $key => $val) {
			if(is_array($val)) {
				echo "$key:\n";
			} else {
				echo "$key => $val\n";
			}
		}
	?>
		
	<?php } ?>
    <p>
	</p>

  </body>
</html>
