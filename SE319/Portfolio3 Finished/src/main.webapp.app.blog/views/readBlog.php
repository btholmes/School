<div class = "row"> 
	<div class = "col-md-9	 col-md-offset-2">
		<div class = "blogPosts" ng-repeat = "post in vm.posts track by $index">
			<div class = "row"> 
				<div class = "col-md-1 postNum"> 
				 <p>Name: {{post.Name}}</p>
				</div>
				<div class = "col-md-9 readPosts">
					{{post.Post}}
				</div>
			</div>
			
		</div>
	</div>
</div>
