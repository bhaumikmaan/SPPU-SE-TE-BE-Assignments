$(document).ready(function () {
  $("body").on("submit", "#searchForm", function (e) {
    let searchText = $("#search").val();
    getMovies(searchText);
    e.preventDefault();
  });
});

$(document).on("pagebeforeshow", "#movie", function () {
  let movieId = sessionStorage.getItem("movieId");
  getMovieDetails(movieId);
});

function movieClick(imdbID) {
  sessionStorage.setItem("movieId", imdbID);
  $.mobile.changePage("movie.html");
}

function getMovies(searchText) {
  $.ajax({
    method: "GET",
    url: `http://www.omdbapi.com?apikey=7d19230d&s=${searchText}`,
  }).done(function (data) {
    console.log(data);
    let movies = data.Search;
    let output = "";
    $.each(movies, function (i, movie) {
      output += `
            <li>
                <a onclick="movieClick('${movie.imdbID}')" href="#">
                    <img src="${movie.Poster}">
                    <h2>${movie.Title}</h2>
                    <p>Release Year: ${movie.Year}</p>
                </a>
            </li>
          `;
    });
    $("#movieList").html(output).listview("refresh");
  });
}

function getMovieDetails(movieId) {
  $.ajax({
    method: "GET",
    url: `http://www.omdbapi.com?apikey=7d19230d&i=${movieId}`,
  }).done(function (movie) {
    let movieTop = `
            <div style="text-align:center;">
                <h1>${movie.Title}</h1>
                <img src="${movie.Poster}">
            </div>
        `;
    $("#movieTop").html(movieTop);
    let movieDetails = `
            <li><strong>Rated:</strong>${movie.Rated}</li>
            <li><strong>Released:</strong>${movie.Released}</li>
            <li><strong>IMDB Rating:</strong>${movie.imdbRating}</li>
            <li><strong>Actors:</strong>${movie.Actors}</li>
            <li><strong>Director:</strong>${movie.Director}</li>
        `;
    $("#movieDetail").html(movieDetails).listview("refresh");
  });
}
