<?php
/**
 * @file
 * Take the user when they return from Twitter. Get access tokens.
 * Verify credentials and redirect to based on response from Twitter.
 */
//////////////////catatan/////////////////////
 /* ide masukkan input secara manual
	redirect -> get $auth_token -> masukkan ke link tag a
	a href=$auth_token -> dapatkan pin $oauth_verifier dari sini
	
	panggil callback ?oauth_token=122345556&oauth_verifier=123pin123

 */
//////////////////catatan///////////////////// 
/* Start session and load lib */
session_start();
require_once('twitteroauth/twitteroauth.php');
require_once('config.php');

/* If the oauth_token is old redirect to the connect page. */
if (isset($_REQUEST['oauth_token']) && $_SESSION['oauth_token'] !== $_REQUEST['oauth_token']) {
  $_SESSION['oauth_status'] = 'oldtoken';
  header('Location: ./clearsessions.php');
}

///////////////////den//////////////
if (isset($_REQUEST['oauth_token'])){
	$_SESSION['oauth_token']=$_REQUEST['oauth_token'];
}
echo 'sesion ------------------<br>';
var_dump($_SESSION);
echo 'sesion ------------------<br>';
///////////////////den//////////////

/* Create TwitteroAuth object with app key/secret and token key/secret from default phase */
$connection = new TwitterOAuth(CONSUMER_KEY, CONSUMER_SECRET, $_SESSION['oauth_token'], $_SESSION['oauth_token_secret']);
echo 'koneksi ------------------<br>';
var_dump($connection);
echo 'koneksi ------------------<br>';

/* Request access tokens from twitter */
$access_token = $connection->getAccessToken($_REQUEST['oauth_verifier']);
echo 'akses token ------------------<br>';
echo '<code>';
var_dump($access_token);
echo '</code>';
echo 'akses token ------------------<br>';
/* Save the access tokens. Normally these would be saved in a database for future use. */
$_SESSION['access_token'] = $access_token;

/* Remove no longer needed request tokens */
unset($_SESSION['oauth_token']);
unset($_SESSION['oauth_token_secret']);

/* If HTTP response is 200 continue otherwise send to connect page to retry */
if (200 == $connection->http_code) {
  /* The user has been verified and the access tokens can be saved for future use */
  $_SESSION['status'] = 'verified';
  header('Location: ./index.php');
} else {
  /* Save HTTP status for error dialog on connnect page.*/
  echo 'eross';
  //header('Location: ./clearsessions.php');
}
