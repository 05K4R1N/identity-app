import React, { useState } from 'react';
import { Row, Col } from 'react-bootstrap';

import Card from '../UI/Box/Box';
import ProfileData from './ProfileData';

const PROFILE_DATA = [
    {
      "id":"1",
      "label":"Apellido(s)",
      "value":"Gamboa Acho"
    },
    {
      "id":"2",
      "label":"Nombre(s)",
      "value":"Oscar Rolando"
    },
    {
      "id":"3",
      "label":"Nacido(a)",
      "value":"05/11/1990",
    },
    {
      "id":"4",
      "label":"En",
      "value":"Cochabamba - Cercado - Cochabamba"
    },
    {
      "id":"5",
      "label":"Estado Civil",
      "value":"Soltero",
    },
    {
      "id":"6",
      "label":"Profesion",
      "value":"Ing. de Sistemas"
    },
    {
      "id":"7",
      "label":"Domicilio",
      "value":"C. Jordan Pje. Loa #316"
    }
];

const Profile = (props) => {
    const [dataProfile, setDataProfile] = useState(PROFILE_DATA);
    return(
        <Card className="profile">
            <Row className="justify-content-md-center">
                <Col xs lg="10">
                    <ProfileData data = {dataProfile}/>
                </Col>
            </Row>
        </Card>
    );
}

export default Profile;