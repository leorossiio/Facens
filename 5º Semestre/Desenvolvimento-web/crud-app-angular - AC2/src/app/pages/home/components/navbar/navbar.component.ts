import { Component } from '@angular/core';

@Component({
  selector: 'app-navbar',
  templateUrl: './navbar.component.html',
  styleUrls: ['./navbar.component.css']
})
export class NavbarComponent {
  activeLink: string = 'home';


  ngOnInit(): void {
    const savedLink = localStorage.getItem('activeLink');
    if (savedLink) {
      this.activeLink = savedLink;
    }
  }
  
  setActiveLink(link: string): void {
    this.activeLink = link;
    localStorage.setItem('activeLink', link);
  }

  logout(){
    localStorage.removeItem('activeLink');
  }
  
}
