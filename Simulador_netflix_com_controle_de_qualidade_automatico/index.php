 <!DOCTYPE html>
 
 <!-- Latest compiled and minified CSS -->
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">

<!-- jQuery library -->
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>

<!-- Latest compiled JavaScript -->
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>

 <html>
    <script src="https://cdn.dashjs.org/latest/dash.all.min.js"></script>
    <style>
        video {
           width: 640px;
           height: 360px;
           margin-left: 25%;
           margin-top: 5%;
        }
    </style>
    <style type="text/css">
    body{
        background-color: #ABA9A9;
    }

        .boxPlace {
           margin-left: 32%;
           margin-top: 5%;
        }
    </style>
    <body>

    <div class="boxPlace">
        <label>Nome do video</label>
        <input name="campoNomeVideo" type="text" id="idCampoVideo" value="" size="30">
        <a class="btn btn-default" type="submit" name="botaoPesquisar" value="">Buscar</a>
    </div>
    
       <div>
           <video data-dashjs-player autoplay src="https://dash.akamaized.net/envivio/EnvivioDash3/manifest.mpd" controls></video>
       </div>
    </body>
 </html>
    